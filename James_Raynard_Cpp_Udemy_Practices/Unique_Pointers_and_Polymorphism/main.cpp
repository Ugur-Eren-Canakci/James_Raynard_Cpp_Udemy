#include <iostream>
#include <memory>
#include <vector>

class Base {
public:
    Base() {
        std::cout << "Base object constructed." << std::endl;
    }

    virtual void print() const noexcept {
        std::cout << "Base" << std::endl; 
    }
};


class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived object constructed." << std::endl;
    }

    virtual void print() const noexcept override {
        std::cout << "Derived" << std::endl; 
    }    
};


int main() {
    
    //• How can unique_ptr be used with polymorphism?
    // Derived objects are stored in memory with their base part at the start. 
    // unique_ptr's contain a private pointer member
    // you can point to a derived object with a base pointer
    // unique_ptr is a wrapper around pointers that make the management simpler
    // hence, polymorphism works with unique_ptr's as well
    
    // Using unique_ptr, write a program which creates a container of
    // polymorphic objects and calls a member function on each object
	std::vector<std::unique_ptr<Base>> vec;
    vec.push_back(std::move(std::make_unique<Base>()));
    vec.push_back(std::move(std::make_unique<Derived>()));
    
    for (const auto& el : vec) {
        el->print();
    }
    
    //What are the advantages of this approach over using new()?
    // We don't have to manually delete the created objects
    
    //Write a function that implements the factory pattern for the Shape hierarchy
    // present in the main of Unique_Pointers project in the "non-practice" workspace
    
    
    return 0;
}
