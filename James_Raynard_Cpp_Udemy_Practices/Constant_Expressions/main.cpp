#include <iostream>

int main() {
    
    //What is meant by the term "constant expression"?
    // values that are calculated in compile-time and not modifyable
    
    //Give some examples of constant expressions
    // any literal, any value that's calculated from literals, and any value that's calculated from values which were calculated from literals
    
    // Can a variable be a constant expression? Write a simple program to
    // illustrate your answer

    constexpr int i{5};
    std::cout << i << std::endl;
    
    //What is the significance of the constexpr keyword?
    // tells the compiler to calculate the value of whatever variable it's put in front of
    // also the value of the constexpr variables cannot be changed
    
    //• What is the difference between a "const" variable and a "constexpr" variable?
    // const is used for runtime operations, indicating that a variable will not be changed if forwarded to a function by reference,
    // or that a member function will not change the called object
    // constexpr variables are calculated in compile-time to be used with no time spent on operations on the variable
    
    
    
	return 0;
}
