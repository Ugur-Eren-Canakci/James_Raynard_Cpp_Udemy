#include <iostream>

int main() {
    
    //Explain briefly what is meant by "lvalue reference"
	// It's a variable that references an lvalue variable
    
    //• Can an lvalue reference be bound to an rvalue?
    // Only if the reference is const
    // having a nonconst reference to an rvalue is something like "I want to refer to this very specific value (that has no name or address)
    // in the future but I want to be able to change it"
    
    //Explain briefly what is meant by "rvalue reference"
    // It's a type of argument functions can have
    // When a function is defined with an rvalue reference, the type of the object has to be movable
    // also the passed value has to be an rvalue
    // If you want to forward an lvalue, you have to forward "std::move(lvalue_object)" into the rvalue reference argument
    
    /*How can we pass an lvalue as an rvalue reference?
    -> Answer is above
     * • Is it safe to use a variable after passing it to std::move()?
     * */
    // No. The value will be stripped off the variable, so the variable might carry garbage values lead to undefined behaviour under dereferencing
    
    
    return 0;
}
