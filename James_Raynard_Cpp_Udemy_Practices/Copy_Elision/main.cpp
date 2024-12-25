#include <iostream>

class Test {
public:
    Test() {
        std::cout << "constructor called" << std::endl;
    }
    Test(const Test& other) {
        std::cout << "copy constructor called" << std::endl;
    }
    ~Test() {
        std::cout << "destructor called" << std::endl;
    }
};

Test func() {
    return Test();
}

Test func2() {
    Test temp {Test()};
    return temp;
}

Test func3(Test test) {
    return test;
}

int main() {
    
    //Explain briefly what is meant by copy elision
    // Compilers don't call for unnecessary copy constructors and destructors when temporary objects were created and used in certain situations
    
    //• Write a simple class. Implement the copy constructor to display a message when called
    
    //**************IMPORTANT*************
    //Which other special member functions do you need to implement, and why?
    // Instructor's answer:
    // A default constructor is required. Since the class defines a copy constructor, the compiler will not synthesize a default constructor for it
    //***********************
    
    //Write a function which returns a temporary object of the class by value
    Test test = func();
    // without copy elision, we would see 4 strings on cout: constructor, copy constructor, destructor, and destructor at the end of main()
    // with copy elision, we'll see only the constructor's message, and the destructor for test
    
    //• Explain what is meant by "Return Value Optimization" and "Named Return Value Optimization"
    // Return Value Optimization constructs the value to be returned directly in the return space instead of 
    // the stack of the function, so that there is no need to construct the same object twice (once in the stack, once in the return space)
    // Named Return Value Optimization is the same thing done to variables initialized in the stack
    
    Test test2 = func2();
    
    //Give another example of when copy elision can occur
    // when a function argument is passed by value
    // Write a simple program to demonstrate this example
    
    Test test3 = func3(test2);
	return 0;
}
