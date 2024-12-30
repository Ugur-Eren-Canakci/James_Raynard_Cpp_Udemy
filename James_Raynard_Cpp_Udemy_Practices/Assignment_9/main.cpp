#include <iostream>
#include <string>
#include "vec_program.h"
#include "list_program.h"
#include "deque_program.h"

/*void print_vector(const std::vector<std::string>& vec) {
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
} */

/*void vec_program() {
    std::vector<std::string> vec;
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
            vec.push_back(user_input);
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
    print_vector(vec);
    std::cout << "Thank you!" << std::endl;
} */


int main() {
    
    //Write a program which will
    // 1) Reads strings entered by the user
    // 2) Store them in a sequential container
    // 3) Print out the strings in the order they were entered
    
    //vec_program p1;
    //list_program p2;
    deque_program p3;
    
    
    return 0;
}
