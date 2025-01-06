#include <iostream>
#include <memory>

class Base {
public:
    Base() {
        std::cout << "Base constructor called" << std::endl;
    }
    
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
private:
    bool crucial_info;
public:
    Derived() : crucial_info(true) {
        std::cout << "Derived constructor called" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor called" << std::endl;
    }
};

void obtain_info() {
    Base* ptr = new Derived();
    std::unique_ptr<Base> base_ptr(ptr);
    std::cout << "Object address: " << ptr << std::endl;
}

void obtain_info_2(auto deleter) {
    Base* ptr = new Derived();
    std::unique_ptr<Base, decltype(deleter)> base_ptr(ptr, deleter);
    std::cout << "Object address: " << ptr << "(don't dereference)" << std::endl;
    throw std::exception();
}

int main() {
    
    //Why is unique_ptr useful for managing pointers which were not returned by new()?
    // initialization of unique_ptr can be done with an existing pointer. 
    // unique_ptr takes ownership of the objects, and calls the appropriate delete function when destructed.
    
    //Why can this be problematical?
    // If the delete function is not supplied by the user, the object will get released from the memory
    
    //Write a program which demonstrates this problem
    obtain_info(); // prints out where the info was obtained from
    // if a user tries to take this address and dereference it, the program will crash? maybe

    //What is a deleter?
    // custom callable object which is called when a unique pointer is destructed
    //How do we use a deleter with unique_ptr?
    // it has to be explicitly declared (with its type going into the template parameters) while initializing a unique pointer
    
    //What happens if we do not know the type of the deleter?
    // we cannot initialize a unique pointer with that deleter since its type is required as a parameter in the initialization
    
    //Write a program which uses a custom deleter
    try {
        obtain_info_2([] (auto ptr) {std::cout << "hello" << std::endl;} );
    }
    catch (std::exception& e) {
        std::cout << "exception caught" << std::endl;
    }
    
    //What would you expect to happen if an exception is thrown?
    // deleter is still called 
    
    
	return 0;
}
