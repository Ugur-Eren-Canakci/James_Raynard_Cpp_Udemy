#include <iostream>
#include "Interface.h"

int main() {
    
    //What is the pImpl idiom?
    //pointer to implementation
    // the implementation is seperated from the interface by creating seperate classes 
    // in the interface class, there's a pointer to an "implementation class" object, and
    // the member functions of the interface class calls the member functions of the implementation class with forwarding and all
    
    // Write a simple program that uses the pImpl idiom with unique_ptr
    // Your program should organize the code in the usual way 
    // (class definition in header file, member function definitions in source file)
    
    Interface interface;
    interface.print_address();
    
	return 0;
}
