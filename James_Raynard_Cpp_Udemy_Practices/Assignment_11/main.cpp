#include <iostream>
#include <map>
#include <string>

void print_map(const std::map<std::string, size_t>& map) {
    for (const auto& pair : map) {
        std::cout << "key: " << pair.first << "\nvalue: " << pair.second << std::endl << std::flush;
    }
}


int main() {
    
    //You will write a program that:
    //Reads words entered by the user
    //Stores the value and length of each word in a suitable std::pair
    //Stores the pair object in a container
    //Prints out all the elements of the container
	
    std::map<std::string, size_t> map;
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
            if (map.insert(std::make_pair(user_input, user_input.length())).second) std::cout << "String was saved." << std::endl << std::flush;
            else std::cout << "String already entered. " << std::endl << std::flush;
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
    print_map(map);
    std::cout << "Thank you!" << std::endl;
    
    
    return 0;
} 
/*
#include <iostream>
#include <vector>
#include <string>

void print_vectors(const std::vector<std::string>& vec1, const std::vector<size_t>& vec2) {
    
    size_t size = vec1.size();
    for (size_t i=0; i<size; i++) {
        std::cout << "key: " << vec1.at(i) << "\nvalue: " << vec2.at(i) << std::endl << std::flush;
    }
}

int main() {
    
    //You will write a program that:
    //Reads words entered by the user
    //Stores the value and length of each word in a suitable std::pair
    //Stores the pair object in a container
    //Prints out all the elements of the container
	
    std::vector<std::string> vec1;
    std::vector<size_t> vec2;
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
            vec1.push_back(user_input);
            vec2.push_back(user_input.length());
            //map.insert(std::make_pair(user_input, user_input.length()));
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
    print_vectors(vec1, vec2);
    std::cout << "Thank you!" << std::endl;
    
    
    return 0;
}
*/