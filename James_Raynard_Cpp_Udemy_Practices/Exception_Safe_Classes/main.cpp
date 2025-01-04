#include <iostream>
#include <string.h>


class String {
private:
    int size;
    char *data;
public: 
    // one-arg constructor from std::string
    String(const std::string& s) : size(s.length()) {
        std::cout << "one-arg std::string constructor called" << std::endl;
        data = new char[size];
        for (int i=0; i<size; i++) {
            data[i] = s[i];
        }
    }
    // one-arg constructor from c-style string
    String(const char* s) : size(strlen(s)) {
        std::cout << "one-arg c-style string constructor called" << std::endl;
        data = new char[size];
        for (int i=0; i<size; i++) {
            data[i] = s[i];
        }
    } 
    
    // default constructor
    String() : size(0), data(nullptr) {
        std::cout << "default constructor called" << std::endl; 
    }
    
    // copy constructor
    String(const String& other) : size(other.size) {
        std::cout << "copy constructor called" << std::endl; 
        data = new char[size];
        for (int i=0; i<size; i++) {
            data[i] = other.data[i];
        }
    }
    
    // assignment operator
    String& operator=(const String& other) {
        char* new_data = new char[other.size];
        delete[] data;
        data = new_data;
        for (int i=0; i<size; i++) {
            data[i] = other.data[i];
        }
        size = other.size;
        
        return *this;
    }
    
    // Destructor
    ~String() {
        std::cout << "Destructor called" << std::endl;
        delete[] data;
    }
    
};
int main() {
    
    //• Implement an exception-safe constructor, copy constructor, assignment operator and destructor for the class shown below
    String a;
    String b("Hello World!");
    
    // Explain how using RAII can ensure the strong exception guarantee for a class's
    // Constructor, Copy constructor, Destructor, Assignment operator
    // Heap allocation is done by "new"s and "delete"s, with deep copying
    // if there's no deep copying needed, every object has their own data members newly initialized
    // if there's deep copying needed, it has to be done carefully
    
	return 0;
}
