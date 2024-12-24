#include <iostream>
#include <string>
#include <vector>

int main() {
    
    //Write out a program with a loop that prints out the characters in a
    //string using
    //• Iterators
    //• Const iterators
    //• Reverse iterators
    //• Const reverse iterators
    
    std::string s {"Hello World!"};
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    
    for (auto it = s.cbegin(); it != s.cend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    
    for (auto it = s.crbegin(); it != s.crend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    
    //Write a program that uses global begin() and end() to print out the elements of an array
    for (auto it = begin(s); it != end(s); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    
    //Write a program that uses a range for loop to print out the elements of a vector
    std::vector<int> vec {1,2,3,4,5};
    for (const auto& el : vec) {
        std::cout << el;
    }
    std::cout << std::endl;
    
    //Add another range for loop that adds 2 to the value of each element
    for (auto& el : vec) {
        el += 2;
    }
    for (const auto& el : vec) {
        std::cout << el;
    }
    std::cout << std::endl;
    
    //Give some examples where a range for loop would not be suitable
    for (auto& el : vec) {
        // vec.push_back(el); if there was proper element access, this loop would never stop since new elements would be pushed in constantly
    }
    
    //Write a loop which removes elements from a vector if they have odd values
    std::vector<int> temp;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if ((*it) % 2 == 0) {
            temp.push_back(*it);
        }
    }
    vec = temp;
    for (const auto& el : vec) {
        std::cout << el;
    }
    std::cout << std::endl;
    
    
    return 0;
}
