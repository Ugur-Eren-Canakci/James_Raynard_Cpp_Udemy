#include <iostream>

int main() {
    
    //Explain why the what() member function of std::exception is virtual
    // what() returns a string, and the purpose for that is to convey information about the error
    // if it weren't virtual, dynamic binding of that function wr. to the object type wouldn't be possible
    
    //• Explain why the destructor of std::exception is virtual
    // rule of thumb for virtual-declared member functions
    // if you have a virtual-defined member function, then the destructor should also be virtual
    // if not, destructor calls might cause memory leaks due to the wrong destructor being called in case of pointer-based activities
    
    /*• The logic_error, runtime_error and their subclasses all have a
    constructor that takes a string argument
    • What is this string used for?
    • What data should we put in this string?
    */
    // the string is returned from what() overrides
    // since it will be returned from what(), it has to contain info about what error/exception arose.
    
	return 0;
}
