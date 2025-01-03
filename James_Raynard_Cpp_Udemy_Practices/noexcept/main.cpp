#include <iostream>

int main() {
    
    //What does it mean if a function is declared as noexcept?
    // compiler makes optimizations on the code
    // ex: not writing the commands for stack unwinding with the noexcept-declared function
    
    //Does noexcept change the signature of the function?
    // noexcept is part of the function's type, but not part of the function's signature
    
    //Why is it useful to know whether a function is noexcept?
    // if a sudden termination happens, you have a place to debug
    // otherwise, the program is optimized for not throwing exceptions from the function
    
    //Are there performance advantages to making a function noexcept?
    // Yes. No exception throw code
    // Also some operators are optimized wr. to this
    
    //• When should noexcept be used
    // whenever possible
    return 0;
}
