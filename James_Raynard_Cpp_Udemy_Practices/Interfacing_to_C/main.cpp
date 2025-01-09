#include <iostream>
#include <vector>
#include "subtract.h"
#include "c_func.h"

int main() {
    
    // What is meant by "name mangling"?
    // C++ compilers craft names for functions to manage function overloading
    
    //Why is name mangling significant when interfacing with C?
    // C doesn't mangle its functions' names, so if we want to use a function defined in C++ to be compatible with C, we have to tell
    // the C++ compiler to not mangle its name
    
    //What do we need to do to avoid having issues with name mangling?
    // extern "C" command works
    // can take a single function, a list of functions, or a whole header file as an argument, and keeps the function name same 
    
    // Write a simple C++ function
    // Write a simple C program that calls your function
	printf("%d\n",subtract(5,3));
    
    /*Write a C function that takes an array argument and prints out all the
    elements in the array
    • Write a C++ program that calls your function using std::vector*/
    std::vector<int> vec {3,1,4,1,5,9};
    print_array(vec.data(), vec.size());
    
    return 0;
}
