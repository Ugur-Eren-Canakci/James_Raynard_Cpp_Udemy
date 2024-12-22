#include <iostream>
#include <string>

int main() {
    
    // Strings have two interfaces: the native one, and the STL container
    // Over 100 member functions
    
    std::string s1{"Hello"}, s2 {"World"};
    
    // Assignment 
    s1 = s2; 
    
    // Appending
    s1 += s2;
    
    // Concatenation
    s1 + s2;
    
    // Comparison
    s1 < s2;
    s1 == s2;
    
    // c_str() member fn returns a copy of the string's data as a C-style string
    // array of chars terminated by null character
    // return value is a pointer to a const char
    // useful for passing C++ strings to functions that take C-style strings  
    
	return 0;
}
