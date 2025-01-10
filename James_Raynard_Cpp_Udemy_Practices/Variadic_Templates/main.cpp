#include <iostream>

template <typename... Args>
void func(Args... args) {
    std::cout << "function called with a list of arguments" << std::endl;
    std::cout << "number of arguments: " << sizeof...(args) << std::endl;
}

template <typename T>
void recursive_func(T t) {
    std::cout << "Final element: " << t << std::endl;
}

template <typename T, typename... Args>
void recursive_func(T t, Args... args) {
    std::cout << "Element: " << t << ", number of remaining elements: " << sizeof...(args) << std::endl;
    recursive_func(args...);
}



int main() {
    
    //What is a variadic function template?
    // it's a function template that can have an arbitrary number of types
    // function arguments have to match the template list, so the syntax is pretty well-defined
    
    //What is meant by the following terms?
    //• Template parameter pack
    //• Function parameter pack
    // Template parameter pack is <typename... Args>
    // Function parameter pack is (Args... args)
    // Replace Args with the list of typenames you'll use in the function template
    // Also replace args with the list of arguments (matching the list of typenames you have above)
    
    //Write down a declaration of a variadic function template
    // Above
    
    /*• Given the following declaration of func and definitions of i, d and s
    template <typename... Args>
    void func(Args... args);
    int i{42};
    double d{0.0};
    string s{"text"};
    • Write down the signature of the functions which would be
    instantiated by the following calls:
    func(s);
    func(i, d, s);
    */
    // func(s) has the signature "void func(std::string&)"
    // func(i,d,s) has the signature "void func(int&, double&, std::string&)"
    
    //What is the purpose of the sizeof... operator?
    // takes in a list of arguments and returns the number of arguments in the list
    
    //Write a simple program that demonstrates the use of the sizeof... operator
    func(1,2,3,4);
    
    //What is a "pack expansion"?
    // replacing the argument list with individual arguments all at once
    // done with "..."
    
    //Describe a typical way of processing a function parameter pack
    // with template recursion
    // we recursively call the function with one less element, usually the first element processed and removed at each step
    // requires a seperate template definition for when the function is called with a single argument, where the list is replaced
    // with only a typename
    
    /*Write a variadic function template which processes its function
    parameter pack
    • As each element in the parameter pack is processed, print it out
    together with the number of elements which remain to be processed*/
    
    recursive_func(1,2,3,4,5);
    std::cout << std::endl;
    
	return 0;
}
