#include <iostream>

class Shape {
public:
    virtual void print() const {
        std::cout << "This is a shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    virtual void print() const override{
        std::cout << "This is a circle" << std::endl;
    }
};

void func(const Shape* ptr) {
    ptr->print();
}

int main() {
    
    //Explain what is meant by static and dynamic binding when calling a member function on an object of a class
    
    // When derived classes have overrides of a base class function, the function call on derived classes is tricky
    // If a derived object is pointed by a Base* pointer, then the compiler will assume that the pointed object is a Base object.
    // This will cause the compiler to call the Base member functions (that have the same signatures in the Derived objects) 
    // from a Derived object, and this decision process where the compiler calls the Base member functions is called 
    // "static binding" of the member functions
    
    // if we want the compiler to not default down to the Base functions when objects are dereferenced from pointers or iterators, 
    // we need the Base version of those function defined as "virtual".
    
    //Which two conditions must apply for dynamic binding to occur?
    // 1) Derived object is pointed by a Base* pointer
    // 2) Base overridden functions are defined "virtual"
    
    //What is a virtual member function?
    //What happens when a virtual function is called through a pointer or reference to the base class?
    // If Base member function definitions are virtual, then when a Derived object is pointed by a Base* pointer, 
    // The compiler will bind the Derived member function onto the Base* pointed Derived object.
    // Same with references
    
    //Explain how virtual functions allow us to pass objects from a class hierarchy to a function which calls a member function
    // the compiler is able to see all overridden function calls. Hence it can bind the correct function inside function definitions.
    // say a function takes in a Base* pointer to dereference the object and call its specific override of the Base member function f.
    // If the base member function f is defined as virtual, then when f is called from a Derived object (that is passed into the function
    // by pointer), the compiler will bind Derived::f onto the function call.
    
    //Write a program which calls such a function
    Shape s;
    Circle c;
    
    Shape* s_ptr = &s;
    Shape* c_ptr = &c;
    
    func(s_ptr);
    func(c_ptr);
    
    

	return 0;
}
