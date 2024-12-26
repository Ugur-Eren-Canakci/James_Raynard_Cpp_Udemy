#include <iostream>
#include <string>
#include <algorithm>

auto find_letter(const std::string s, const char letter) {
    if (s.find(letter) != std::string::npos) {
        std::cout << "Letter found at position " << s.find(letter) << std::endl; 
    }
    else std::cout << "Letter not found." << std::endl;
    return s.find(letter);
}

int main() {
    
    // Write a program which uses an STL algorithm to find the first occurrence of a letter in 
    // an std::string object. Display the index of this first match
    std::string s = "Hello world!";
    find_letter(s, 'l');
    //Check that your program correctly handles the case where the searched-for letter is not found
    find_letter(s, 'a');
    
	return 0;
}
