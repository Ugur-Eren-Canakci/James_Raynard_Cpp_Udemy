#include <iostream>

int main() {
    
    //What is meant by an error code in C or C++?
    // it's a value returned by the code under certain circumstances of run-time
    
    //• Give some of the disadvantages of error codes
    // Not possible to extract much info just by looking at the error code
    // If there are too many possible error codes, management of these is a headache
    // Constructors don't have return values, so there's no way to know if a constructor call was successful or not
    
    // Briefly explain why exceptions are preferable to error codes
    // Exceptions are objects, so they can store info about the error
    // No need to return an exception object, there are mechanisms that "catch" exceptions
    
    //Give one disadvantage of exceptions
    //In certain systems the flow of the program has to be non-interrupted. Exceptions kinda break this rule.
    // Ex: games, embedded systems, error logging and handling
    
    
    
    
	return 0;
}
