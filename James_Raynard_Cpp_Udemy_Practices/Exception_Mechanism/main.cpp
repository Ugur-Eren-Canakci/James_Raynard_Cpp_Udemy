#include <iostream>

int main() {
    
    /* When an exception is thrown in a try block, describe what happens
    to:
    • The thrown object
    • The local variables in the try block
    • The program control flow
    */
    // thrown object is stored in a special memory block
    // local variables are destructed
    // current scope is closed/terminated and the outer scope is searched for a suitable catch block
    
    //• Explain what is meant by the term "stack unwinding"
    // searching for a catch block that can take in the thrown exception object in the function stack
    // if the topmost function block doesn't contain a viable catch block, that function is popped
    // the search continues on the next function in the function stack
    // this is recursively repeated until either a viable catch block is found, or main is reached
    // if main is reached, program calls std::terminate()
    
    /*A catch block can throw its exception object again. What is the syntax
    for doing this?
    • How is the rethrown exception handled?
    */
    // add "throw;" as the last line of the catch block
    // current catch block is closed, so another catch block is searched for on the function body that 
    // contains the closed catch block
    
    //• Give an example where this would be useful
    // If the program-generated exception object doesn't contain enough info, exception can be altered and thrown again 
    // to be caught by another catch block
    // some logging activities can be done when the error is first encountered
    
    

	return 0;
}
