#include <iostream>
#include <cstring>

class String {
private:
    int size;
    char* data;
public:
    String(const std::string& s) : size(s.length()) { // std::string constructor
        std::cout << "std::string constructor" << std::endl;
        this->data = new char[size];
        for (int i=0; i<size; i++) {
            data[i] = s[i];
        }
    }
    
    String(const char* s) : size(strlen(s)) { // c-style string constructor
        std::cout << "c-style string constructor" << std::endl;
        this->data = new char[size];
        for (int i=0; i<size; i++) {
            data[i] = s[i];
        }
    }
    
    String() : size(0), data(nullptr) { // no-args constructor
        std::cout << "no args constructor" << std::endl;
    }
    
    String(const String& other) : size(other.size) {
        std::cout << "copy constructor" << std::endl;
        data = new char[size];
        for (int i=0; i<size; i++) {
            data[i] = other.data[i];
        }
    }
    
    String& operator=(const String& other) {
        std::cout << "copy assignment" << std::endl;
        if (&other != this) {
            size = other.size;
            delete[] data;
            data = new char[size];
            for (int i=0; i<size; i++) {
            data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    String(String&& other) noexcept : size(other.size)  {
        std::cout << "move constructor" << std::endl;
        data = other.data;
        other.data = nullptr;
    }
    
    String& operator=(String&& other) noexcept {
        std::cout << "move assignment" << std::endl;
        if (&other != this) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
        }
        return *this;
    }
    
    ~String() {
        std::cout << "destructor" << std::endl;
        delete[] data;
    }
};

int main() {
    
    // When writing a move constructor, is moving the data members of the argument object sufficient?
    // Nope. Resource allocations must be thoroughly investigated as data that's not in the stack is not affected by move operations
    
    /*Add move operators to the String class
    • Write a program to test your class
    • Make sure it does not crash or leak memory
     * */
	String s1("Hello World! s1");
    String s2(std::string("Hello World! s2"));
    String s3 = s1;
    String s4 = std::move(s3);
    String s5(std::move(s4));
    String s6{std::move(s5)};
    
    return 0;
}
