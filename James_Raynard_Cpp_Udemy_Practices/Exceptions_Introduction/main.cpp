#include <iostream>
#include <vector>

int main() {
    
    //Write a simple program in which there is a run-time error condition, but there is no exception-handling code
	/*std::vector<int> vec; // default init, size is zero
    std::cout << vec[1] << std::endl;
    */
    //What happens when this program is run? Explain your results
    // The program is terminated without any outputs.
    
    //• What keyword do we use to tell the compiler to generate exceptionrelated code?
    // try
    
    //What keyword do we use to inform the compiler that some code is an exception handler?
    // catch
    
    //How do we specify which type of exception the code should handle?
    // catch takes in an argument. we can choose this argument however we want.
    
    //We want to write an exception handler that can deal with different
    //sub-types of an exception class. Is there an easy way to do this?
    // yes. by taking a const reference of the exception object that's generated in runtime.
    // std::exception has virtual functions, and (I assume) compiler constructs an exception object by:
    //     std::exception* = new exception_subclass;
    // so that when the subclass object is passed into the catch block, the functions that are called in the block
    // are dynamically binded
    
    //Rewrite your program from the first exercise so that it handles the exception
    std::vector<int> vec;
    try {
        std::cout << vec.at(1) << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }    
    // Make it print out a message which describes the error condition
    // vector::_M_range_check: __n (which is 1) >= this->size() (which is 0)
    
    //What happens if an exception is thrown in a try block and none of the associated catch blocks can handle it?
    // the program keeps searching for an appropriate catch block in the current scope
    // if there's no suitable catch blocks, current function call is removed from the stack
    // the search continues in the next function call in the stack
    // this keeps happening until either a suitable catch block is found, or all the functions in the stack are popped
    // i.e. either a catch block is found, or the program terminates due to main() being popped from the function stack
    
    
    return 0;
}
