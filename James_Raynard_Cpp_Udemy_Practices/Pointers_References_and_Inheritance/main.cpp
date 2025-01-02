#include <iostream>

class Shape {
public:
    void print() {
        std::cout << "Shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void print() {
        std::cout << "Circle" << std::endl;
    }
    
    void circle_fn() {
        std::cout << "Circle fn" << std::endl;
    }
};

int main() {
    
    //• Write a simple inheritance hierarchy with a base class "Shape" and a derived class "Circle"
	// In the header
    
    /*Write a program which
    • Creates a Circle object and a Shape* to it
    • Creates a Shape object and a Circle* to it
    */    
    Circle c;
    Shape* c_ptr = &c;
    
    Shape s;
    //Circle* s_ptr = &s; error: invalid conversion from 'Shape*' to 'Circle*'
    
    //• Explain your results
    // Due to the assignment of &s, the compiler is able to deduce that s_ptr is a Shape* object, but our explicit type definition
    // forces the compiler to do a type conversion. This specific conversion is not possible since base class pointers
    // cannot be converted to derived class pointers
    // If it were possible, we could call a Derived::fn(derived_class_member) from a Base object, and derived_class_member argument 
    // wouldn't have come up, leaving the function uncallable
    
    //Write a similar program, but this time use references instead of pointers
    Circle circle;
    Shape& ref_circ = circle;
    
    Shape shape;
    //Circle& ref_shape = shape;
    // error: invalid initialization of reference of type 'Circle&' from expression of type 'Shape'
    // again, same situation with pointers
    
    /*Add some member functions to your classes
    • A member function in Shape which is reimplemented in Circle
    • A member function which is unique to Circle
    */
    
    //Write a program which creates a Circle object and a Shape* which points to the Circle object
    //c and c_ptr work
    
    //c_ptr->circle_fn();
    // error: 'class Shape' has no member named 'circle_fn'
    
    //Explain your results
    // the compiler can't access the circle_fn's memory address, as that address is kept outside of the Shape part of Circle objects
    
    return 0;
}
