#include <iostream>

int main() {
    
    //• Give some characteristics of lvalues
    // they have a name and an address
    // can be pointed or referred by other lvalues
    
    //• Give some characteristics of rvalues
    // anything that has no name or a memory address is an rvalue
    // cannot be referred or pointed as they have no memory address
    // can be a literal or a temporary object
    
    //• Explain what is meant by the terms "prvalue", "xvalue", "lvalue" and "glvalue" in modern C++
    
    // p(ure) rvalues are literals as they strictly are just values that can be assigned to a variable
    
    // (e)x(piring) values are temporary objects. These are still rvalues but may contain some lvalue data that
    // can be utilized 
	
    // lvalues are above
    
    // g(eneralized) lvalues are lvalues and temporary objects
    // "generalized" comes from the fact that the temporary objects can hold info inside a data member(who has a name)
    
    
    return 0;
}
