#include <iostream>

/*[[noreturn]]*/ void func() {
    std::cout << "func call" << std::endl;
}

int main() {
    
    // What is an attribute?
    // not a part of the language
    // there to communicate with the compilers to act in a certain way 
    
    //What is the purpose of the "noreturn" attribute?
    // tells the compiler that a function will not return a value
    // for example, if a function has a while loop that never stops, 
    // [[noreturn]] makes it so that the control stays in that function forever
    
    // Write a simple program that uses the noreturn attribute
    func();
    
    /*What is the purpose of the "deprecated" attribute?
    • Why is the "deprecated" attribute useful?
    • Write a simple program that uses the deprecated attribute
    */
    // when a function with [[deprecated]] attribute, a warning will popup after building,
    // saying that the function is deprecated
    
    /*What is the purpose of the "fallthrough" attribute?
    • Why is the fallthrough attribute useful?
    • Write a simple program that uses the fallthrough attribute
    */
    // used in switch statements. some cases will execute the same response, and [[fallthrough]] makes it easier for the 
    // compiler to build the program for that situation
    
    /*What is the purpose of the "nodiscard" attribute?
    • Write a simple program that uses the nodiscard attribute
    • What does it mean if a struct is declared as nodiscard?
    • Write a simple program that declares a struct as nodiscard*/
    
    // when a function with [[nodiscard]] attribute is called, its return value will be disregarded
    
    /*What is the purpose of the " maybe_unused " attribute?
    • Write a simple program that uses the maybe_unused attribute*/
    // makes the compiler not show a warning if a variable is not used after its declaration
    
    
    
    
    return 0;
}
