#include <iostream>

int main() {
    
    //Why is separating the interface of a class from its implementation important in object-oriented programming?
    // the users don't need to know what happens on the implementation side of things
    
    //Why is it difficult to completely separate the interface and implementation of a C++ class?
    // interface forwards its arguments to the implementation functions, which are visible in the interface definitions and declarations
    
    //What problems can this cause when compiling large applications?
    //when you want to patch your program, you might need to compile the whole project if you don't implement seperate handle and body
    
    //What is the the Handle-Body pattern?
    // Handle contains all the interface, body contains all the implementation
    
    

	return 0;
}
