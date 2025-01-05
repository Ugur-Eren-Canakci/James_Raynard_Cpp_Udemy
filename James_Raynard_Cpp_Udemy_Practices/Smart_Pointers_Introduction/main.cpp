#include <iostream>

int main() {
    
    //Briefly describe the traditional C++ pointer
    // binary integer that represents a memory address
    // has to be defined w.r. to the type of the object it points to
    // can be used to manage heap allocation
    // arithmetic possible since it's an integer
    
    //Briefly explain why using traditional C++ pointers is undesirable
    //heap allocation is messy as allocated memory might not be released even though the pointer might
    // for stack variables, references are perfectly fine, and already implements pointer logic
    
    //What is a "smart pointer"?
    // An object with a private raw pointer member
	//• Describe briefly how a smart pointer manages memory
    // its constructor allocates memory, and destructor releases memory
    
    //Why are smart pointers considered preferable to traditional pointers?
    // already holds a raw pointer, so anything done with raw pointers can be done with smart pointers
    // memory release is automatic, so no chance of memory leaks
    // also has additional features such as reference counting and immutability 
    
    
    
    return 0;
}
