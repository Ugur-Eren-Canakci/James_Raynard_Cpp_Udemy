#include <iostream>

int main() {
    
    //Explain what is meant by the "Rule of Zero"
    //If you dont need to define a destructor, then similarly you don't need to define copy or move operators
    
    //When should the Rule of Zero be used?
    // If there's no resource management
    
    //Explain how to make a move-only class
    // declare the copy operators as deleted
    //Give an example of when a move-only class could be useful
    // When copying an object is not wanted or problematic to the program flow
    
    //Explain how to make an immoveable class
    // Declare the move operators as deleted
    //Give an example of when an immoveable class could be useful
    // No idea

    //• Explain how to make a copy-only class
    // declare move operators as deleted
    //  Why are copy-only classes not recommended?
    // when the copy constructor is called with a move(arg) call, the compiler might invoke the deleted move operators
    // also this doesn't provide any useful implementation
    
    
	return 0;
}
