#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    
    //Write a program which binds a child object to a pointer to its base class
    /*Both classes have a non-virtual destructor function
    • The destructor body prints out the name of its class*/
	
    Base* derived_ptr = new Derived;
    delete derived_ptr;
    // Only the base destructor was called
    
    //Change your program so that the destructor is declared virtual in the base class
    // Derived destructor called before the base destructor
    
    //• Why is this important?
    // If the derived class is managing resources (heap allocation, database stuff, etc.)
    // synthesised destructors are not virtual, so the resource management is off the limits for the compiler to manage 
    
    //• In general, what should we do when writing a class which has virtual member functions?
    // virtual functions in base class => base destructor also should be virtual
    
    
    
    return 0;
}
