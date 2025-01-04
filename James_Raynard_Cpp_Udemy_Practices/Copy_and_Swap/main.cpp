#include <iostream>

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
        String temp(other);
        std::swap(*this, other);
        return *this;
    }
    
    // Destructor
    ~String() {
        std::cout << "Destructor called" << std::endl;
        delete[] data;
    }
    
};

int main() {
    
    // Describe how to write an assignment operator for an RAII class that provides the strong exception guarantee
    // copy-construct a temporary object with the assigned object as the argument
    // swap the temp. object with *this
    // return *this (for chain assignment)
    
    //• Briefly explain how your solution provides the strong exception guarantee
    // swap is noexcept. Hence it cannot throw any exceptions
    // return doesn't throw exceptions as well
    // the only command that might raise an exception is the copy constructor call
    // if it throws an exception, the temporary object is destroyed, and the original object is not altered anyhow
    
    //• Implement your solution for the class String
    // Seen above
    
    return 0;
}
