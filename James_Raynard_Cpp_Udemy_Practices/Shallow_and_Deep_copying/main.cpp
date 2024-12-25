#include <iostream>
#include <string>

class String {
private:
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    int size;
    char *buffer;
public:
    String(const std::string& str) : size(str.size()) {
        std::cout << "default constructor called with " << str << std::endl;
        char* arr = new char[this->size];
        for (int i=0; i<this->size; i++) {
            arr[i] = str[i]; 
        }
        buffer = arr;
    }
    
    ~String() {
        std::cout << "destructor called" << std::endl;
        delete[] buffer;
    }
    
    String(const String& other) : size(other.size) {
        std::cout << "copy constructor called" << std::endl;
        char* arr = new char[other.size];
        for (int i=0; i<other.size; i++) {
            *(arr + i) = *(other.buffer + i);
        }
        buffer = arr;
    }
    
    String& operator=(const String& other) {
        std::cout << "assignment operator called" << std::endl;
        if (&other != this) {
            this->size = other.size;
            char* arr = new char[this->size];
            for (int i=0; i<other.size; i++) {
                *(arr + i) = *(other.buffer + i);
            }
            buffer = arr;
        }
        return *this;
    }
    
};


std::ostream& operator<<(std::ostream& os, const String& s) {
    for (int i=0; i<s.size; i++) {
        os << s.buffer[i];
    }
    return os;
}

int main() {
    
    
    //What does an RAII class need to do when managing a resource's lifetime?
    // Answer: it should manage the resource in copy constructors, assignment operators and deconstructors
    
    //What is meant by "shallow copying"?
    // Only copying the attribute values onto the new object
    
    //• When is shallow copying dangerous?
    // if the object acquires memory in the heap and holds a pointer to that memory as an attribute
    
    //What is meant by "deep copying"?
    // taking care of allocated resources explicitly, without allowing for possible errors
    
    //How does a deep assignment differ from a deep copy?
    // if an object is assigned onto itself, there shouldn't be any changes to that object
    
    //What is the "Rule of Three"?
    // if you defined one of "copy constructor, assignment operator, destructor", then you should define the other two
    
    //Implement the "rule of three" operators for the class shown below using the RAII idiom
    // Answer: class definition in the header
    
    String s1 {"Hello"};
    String s2 {s1};
    String s3 = s1;
    
    std::cout << s1 << s2 << s3 << std::endl; 
    
	return 0;
}
