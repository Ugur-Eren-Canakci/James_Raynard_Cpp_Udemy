#include <iostream>

/*C++11 has constexpr functions   
    arguments are constexpr
    return value is a constexpr
    Executed at compile time
    Implemented using a compile-time interpreter which supports most of C++
    Written in normal C++ code
    Understandable error messages
    
To make a function constexpr, we put constexpr keyword before its return type
    Ex:
    constexpr double miles_to_km(double miles) { return miles*1.602; }

A constexpr function must be "pure"
    It cannot modify its arguments
    Cannot modify global/static variables
    
constexpr functions are implicitly defined as inline
    this is because the function call is omitted
    
    this also means we can have multiple definitions
    
    can be used in header-only libraries
    
A constexpr function can be called with arguments that are not constant expressions
    In this case the return value will not be a constexpr
    The function will be evaluated at runtime
    This avoids the need to write an otherwise identical version of variables
    
Applications of constexpr functions:
    useful for performing calculations at compile time
        the calculation is done once (during the development process) instead of every time the program is run
        
        no runtime overhead
        
        reduces energy consumption
        
In C++11, the body of a constexpr function could only contain a single return statement

In C++14, these requirements were relaxed and constexpr functions can contain:
    1) multiple statements
    2) variable declarations (provided that they're initialized and not static)
    3) flow control(conditionals and loops, even range-loops)
    
    however, the body of a consexpr function may not contain any code which causes an action at runtime
        e.g. new/delete, calling virtual function, throwing exception
        

a member function can be made constexpr
    takes constant expression arguments, returns a constant expression
    
    this is different from a member function which is const
    
    In C++11 constexpr member functions were also const
        In C++14 constexpr member functions are allowed to modify "this", unless also declared as const
        
    
classes and structs can have members which are constexpr
    Initialized from constant expression
    Cannot be modified
    
    these members must also be static
        (if not static, then it's bound to a runtime object, which is not possible for constexpr variables)
        otherwise, the data members will not be available at compile-time 
    */

constexpr int func(int a, int b) {
    return a+b;
}

constexpr double circle_circumference(double radius) {
    return radius*2*3.14;
}

int main() {
    
    //What is a constexpr function?
    // takes in constexpr arguments and returns constexpr values
    // if it takes variables that are not constexpr, then the return value is not constexpr and requires runtime call

    //• How do we make a function constexpr?
    // by adding constexpr before the return type
    
    //What are the requirements for a constexpr function?
    // cannot modify its arguments or global/static variables
    
    // What happens if a constexpr function is called with arguments that
    // are not constant expressions?
    // execution is done at runtime
    // return value will not be a constexpr
    
    //Why is this useful?
    //avoids the need to write an otherwise identical version of variables
    // Ex: say
	return 0;
}
