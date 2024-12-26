#include <iostream>


auto func(std::string str) {
    return [str] (std::string s) { return str + " " + s; };
}


int main() {
    
    
    //What type of variable is used to store a lambda?
    // the compiler creates a functor with a unique name that's not available directly. So initializing it requires typename "auto".
    
    //Write a function that takes a string and returns a lambda expression
    //• The lambda will take another string as its argument
    //• It combines this string with the function's argument string and returns the result
    // func
    
    //• Write a program which calls your function and stores the resulting lambda expression
    
    auto greeter = func("Greetings");
    auto cusser = func("Fuck off");
    
    std::cout << cusser("Ugur") << std::endl;
    std::cout << greeter("Ugur") << std::endl;
    
    //Can storing a lambda that performs capture by reference be dangerous?
    // captured variables are stored as private data members
    // captured references are data members that are references
    // if the referenced value doesn't exist anymore, then you cannot get a value from it
    // so that variable creates a data member that references a non-existent thing
    // if the function body of the lambda expression uses that data member, then the program is likely to crash
    
    


	return 0;
}
