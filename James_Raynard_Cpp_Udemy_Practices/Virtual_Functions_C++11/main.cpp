#include <iostream>

class Shape {
public:
    virtual void print(/*int x*/) const {
        std::cout << "This is a shape" << std::endl;
    }
};

class Circle /*final*/ : public Shape {
public:
    virtual void print() const override /*final*/ {
        std::cout << "This is a circle" << std::endl;
    }
};


class DeluxeCircle : public Circle {
public:
    virtual void print() const override {
        std::cout << "This is a deluxe circle" << std::endl;
    }
};

int main() {
    
    //• What effect does the override keyword have?
    // Tells the compiler to check if the function that has this keyword actually overrides a virtual function from a base class
    
    //Write a program which uses the override keyword
    // In the header
    
    //• Change the signature of the member function in the child class, so that it does not reimplement any base class member function
    // Remove the comment signs around "int x" in the virtual base member function to see the effect
    
    //What effect does the final keyword have?
    // Tells the compiler to check if the function/class that has this keyword is further derived
    
    //• Write a program in which a member function is declared "final" and a child class reimplements it
    
    //• Write a program in which a class is declared "final". Derive a child class from it

	return 0;
}
