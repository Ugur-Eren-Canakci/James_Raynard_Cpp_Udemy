#include <iostream>

int main() {
    
    //Give some situations which typically involve copying in C++
    // pass-by-value arguments->object is copied into the function's body on the stack, so that the original object isn't changed by default
    // function return values->after all commands are done, function will pop out of the stack, and the return value has to be
    // returned to the caller body. hence a copy of it has to be stored outside the function body
    
    //• Why are these copy operations considered undesirable?
    // If the copied objects are vast in data/information or require resource management, things might get dirty
    
    //Does traditional C++ provide anything to reduce the copying overhead?
    // Copy elision is done so that the return value is created "in place", where the caller body is supposed to obtain the return value
	
    /*• Describe what happens what the following operations are performed:
    • Copying
    • Swapping
    • Moving
    */
    
    /* set x and y to be objects of same type
     * copying of y into x: y's value is copied and assigned onto x's memory slot
     * swapping: x's value is assigned onto a temp value, y's value is assigned to x, and temp value is assigned to y
     * moving: y's buffer becomes invalid, and x now represents the old buffer of y
     * recall that a buffer is a contiguous block of memory
     * */
    return 0;
}
