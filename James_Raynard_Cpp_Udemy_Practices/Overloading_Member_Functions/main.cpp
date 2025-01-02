#include <iostream>

class Vehicle {
public:
    void print_type() {
        std::cout << "Vehicle " << std::endl;
    }
    
    void print_type(bool flag) {
        std::cout << "Vehicle_" << std::endl;
    } 
};

class Aeroplane : public Vehicle {
public:
    void print_type() {
        std::cout << "Aeroplane " << std::endl;
    }
    
    void print_type(bool flag) {
        Vehicle::print_type(flag);
        std::cout << "Aeroplane_" << std::endl;
    }
};

class Car : public Vehicle {
public:
    using Vehicle::print_type;
};

int main() {
    
    //Explain what is meant by "overloading" an inherited member function
    // Redefining a (non-private) member function of a Base class inside a Derived class
    
    //Write a simple program with an overloaded inherited member function
    Aeroplane a;
    a.print_type();
    
    //Explain what is meant by a "hidden" member function
    // Above, Vehicle::print_type is hidden from Aeroplane objects, as Aeroplane has its own print_type function
    
    // Write a simple program which demonstrates this problem
    bool flag;
    // a.print_type(flag);
    // When compiled, compiler gives "error: no matching function for call to 'Aeroplane::print_type(bool&)'"
    // *** Added an overload of print_type to Aeroplane that will cause the compiler to not push this error ***
    
    //Describe a solution to hidden member functions which works in any version of C++
    // Assume fn is defined in Base class, and overloaded in Derived class.
    // Derived::fn() { Base::fn(); other_commands;}
    // The definition above calls the base version of fn inside the derived version
    
    //Are there any drawbacks to this solution?
    // Obviously you might not want to call every command inside the base function. 
    // Ex: with a logging function, the base class might forward info about a strict Base object, which may not be utilized by the Derived class
    a.print_type(flag);
    
    //Describe a solution to hidden member functions which works with C++11 onwards
    // In the right access bracket, call "using Base::overloaded_fn;" so that the Base member functions are not hidden from Derived objects
    
    //Write a simple program which uses this solution
    Car b;
    b.print_type();
    b.print_type(flag);
	return 0;
}
