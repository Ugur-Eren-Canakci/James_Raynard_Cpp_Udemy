#include "list_program.h"
#include <list>
#include <string>
#include <iostream>


list_program::list_program()
{
    std::list<std::string> list;
    char choice;
    
    std::cout << "Welcome to the program!" << std::endl;
    std::cout << "=======================\n\nPlease enter \'s\' if you want to start the program: ";
    std::cin >> choice;
    std::cin.clear();
        
    bool flag = false;
    if (choice == 's') flag = true;
    
    while (flag) {
        std::cout << "Please enter a string: ";
        std::string user_input;
        std::cin >> user_input;
        if (user_input.size() < 1) {
            std::cout << "Invalid string. Please enter again. " << std::endl;
            std::cin.clear();
        }
        else {
            list.push_front(user_input);
            std::cout << "String was saved." << std::endl;
        }
        std::cin.clear();
        bool flag2 = true;
        while (flag2) {
            std::cout << "If you want to continue, please enter 1.";
            std::cout << "\nIf you want to quit and print the saved strings, please enter 2.";
            std::cout << "\n Choice:";
            std::cin >> choice;
            if (choice == '2') {
                flag2 = false;
                flag = false;
            }
            else if (choice == '1') flag2 = false;
            else {
                std::cout << "\nPlease enter a valid choice.\n";
                flag2 = true;
            }
        }
    }
    
    std::cout << "Saved strings:\n";
    print_list(list);
    
    std::cout << "Thank you!" << std::endl;
}

list_program::~list_program()
{
}

void list_program::print_list(const std::list<std::string>& list) {
    for (const auto& el : list) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}