#include <iostream>


template <typename T>
void func(T&& t) {
    std::cout << "forwarding reference called" << std::endl;
}

int main() {
    
    //Is it possible to create a reference to a reference?
    // Yes, with type aliases and templates
    
    //Write a simple program to illustrate your answer
    using intref = int&;
    int a = 5;
    intref b = a;
    intref& c = b;
    
    std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    
    a++;
    
    std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    
    //What is meant by "reference collapsing"?
    // reference to a reference object is simply carrying the same value in the referred original variable
    // to different names. Hence, there's no point in having extra layering, you can just refer to the first 
    // referred object. This is automatically done by the compiler.
    
    // What rules are used for reference collapsing in C++11?
    // If we set an rvalue reference to an rvalue reference object, then the outcome is an rvalue reference to the original object
    // Otherwise, if there's any lvalue reference at any point of these declarations, then the reference to the reference 
    // object is an lvalue reference
    
    //What is the effect of putting "&&" after an argument of specific type?
    //func(Test&& x);
    // overloads the function to take only rvalue objects to x
    
    //In a template function, what effect does putting "&&" after a
    //template parameter argument have?
    //template <typename T>
    //func(T&& x);
    // tells the compiler to take any object
    // if an lvalue is forwarded into func, then T&& is interpreted as reference to the lvalue
    // if an rvalue is forwarded into func, then T&& is interpreted as reference to the rvalue
    
    //Write a simple program to demonstrate that a function with a
    //forwarding reference argument can be called with either an lvalue or
    //an rvalue
    
    func(5);
    int x=3;
    func(x);
    
    /*Consider this function with an argument which is a forwarding reference
    template <typename T>
    func(T&& x);
     * What will be the prototype of the instantiated function if it is called
    with
    • An lvalue object of class Test
    • An rvalue object of class Test
    • (For simplicity, assume that the instantiated function has the same name)
    */
    // lvalue:
    // func(Test& x) ...
    // rvalue:
    // func(Test&& x) ...
    
    // Explain why forwarding references are useful
    // if you have a function with n arguments, and that function is going to take either lvalues or rvalues,
    // then there has to be 2^n explicit declarations and definitions of the same function
    // With forwarding reference, compiler deduces what category of value is forwarded into the functions
    // and then defines the functions for those categories of values.
    return 0;
}
