#include <iostream>
#include <vector>

decltype(auto) a{3.14};

template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1+t2){
    return t1+t2;
}

auto make_vector = [] (auto x, size_t n) {
    return std::vector<decltype(x)>(x,n);
}

int main() {
    
    //Describe the decltype keyword
    // only works in compile-time
    // returns the type of the argument it's passed
    
    //What are the main differences between the auto keyword and decltype?
    // auto doesn't take on const and reference
    // decltype takes on everything from the value
    
    //Write a simple program to illustrate your answer
    const int x{5};
    auto y = x;
    decltype(x) Z{3};
    y++;
    std::cout << y << std::endl; 
    // y increments since auto doesn't take on "const" from x
    // z cannot increment, the compiler will put out an error
    
    /*• What is the result of decltype when the argument is
    • A named variable
    • An expression which returns an lvalue
    • A prvalue
    • An xvalue
    */  
    // named variable -> lvalue
    // expression that returns an lvalue -> lvalue reference
    // prvalue -> lvalue 
    // xvalue -> rvalue reference
    
    /*• What happens if the argument to decltype is "auto"?
    • Write a simple program to illustrate your answer
    */
    // compiler deduces the assigned value's type, and puts it as the type of the variable
    std::cout << a << std::endl;
    
    /*• Give two applications of decltype
    • Write a simple program to illustrate your answer
    */
    // both in header
    
    
    
    
	return 0;
}
