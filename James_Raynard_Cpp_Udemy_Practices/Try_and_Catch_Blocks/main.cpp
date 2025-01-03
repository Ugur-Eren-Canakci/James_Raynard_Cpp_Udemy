#include <iostream>
#include <vector>

void func(std::vector<int>& vec) {
    std::cout << vec.at(2) << std::endl;
}

void func_2() {
    std::vector<int> vec;
    try {
        try {
            func(vec);
        }
        catch (const std::runtime_error& e) {
            std::cout << "runtime error" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "exception" << std::endl;
    }
    
}
int main() {
    
    //When is it useful to have more than one catch block after a try block?
    // If you can suspect what exception is likely to come out, and if this exception is a subclass of the exception class you use
    
    // If more than one of the catch blocks is able to handle a certain exception, how does the program decide which one to invoke?
    // catch blocks can take derived objects if it takes reference to a base class. So the exception object is forwarded into
    // the first catch block that can take either the exact same class or a more base class in the same hierarchy
    // so we place the catch blocks in reverse order of the hierarchy, starting from the most sub class and going up to the most base class
    
    //When writing an exception handler, how should the exception object be passed to it? Give a reason for your answer
    // by reference, and const reference if the exception object will not be altered
    // if the catch block takes a pass-by-value argument, a derived object will be caught by that catch block
    // due to being pass-by-value, the exception object will be copied into the catch block
    // hence, only the base part of the exception object will be forwarded, missing possibly important info kept in the 
    // derived part of the exception object
    
    //What guidelines should we follow when writing an exception handler?
    // Written in the second answer
    
    //Write a simple program which has a nested try/catch block
    //Throw an exception which can only be handled by an outer catch block
    /*Write a simple program which calls a function
    • The function throws an exception inside a try block
    • The exception can only be handled by a catch block which is in the
    function's caller
    */
    func_2();
    
    
    
	return 0;
}
