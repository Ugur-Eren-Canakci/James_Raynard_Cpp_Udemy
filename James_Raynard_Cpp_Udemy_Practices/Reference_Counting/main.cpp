#include "String.h"
#include <iostream>
#include <vector>

class String;

std::string display_string(const char* s) {
    std::string res{};
    for (auto it = s; *it != '\0'; it++) res+=*it;
    return res;
}

int main() {
    
    //Briefly explain what is meant by "reference counting"
    // Used in situations where a data variable is used by many objects at the same time
    // i.e. how many objects refer to the same value/object
    
    //• Describe how a "reference counter" is used to manage a shared resource
	// we keep a counter in the objects to be incremented when an object is copy-constructed and 
    // decremented when an object is destructed
    
    //Convert the String class from previous exercises into a referencecounted object
    //Add any necessary member(s)
    
    std::cout << std::boolalpha;
    
    // c-style string constructor
    String s1("Hello World!");
    // std::string constructor
    String s2(std::string("Hello World!"));
    // default constructor
    String s3{};
    // copy constructor
    String s4(s3);
    String s5(s1);
    // copy assignment constructor
    String s6(s4);
    String s7(s5);
    // move constructor
    String s8(std::move(s1));
    // move assignment operator
    String s9 = std::move(s8);
    
    std::vector<String> vec;
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    vec.push_back(s4);
    vec.push_back(s5);
    vec.push_back(s6);
    vec.push_back(s7);
    vec.push_back(s8);
    vec.push_back(s9);
    
    for (int i=0; i<9; i++) {
        std::cout << "s" << i+1 << ": ";
        std::cout << "length: " << vec.at(i).show_size() << ", string: ";
        
        if (vec.at(i).show_string() != nullptr) {
            auto str = vec.at(i).show_string();
            std::cout << display_string(str);
        }
        else std::cout << "null";
        
        std::cout << ", count: " << vec.at(i).show_counter() << std::endl;
    }
    
    return 0;
}
