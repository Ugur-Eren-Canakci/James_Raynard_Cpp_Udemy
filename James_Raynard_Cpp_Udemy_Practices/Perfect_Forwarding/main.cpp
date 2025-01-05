#include <iostream>

template <typename T>
void g(T& t) {
    std::cout << "pass-by-nonconst-ref" << std::endl;
}

template <typename T>
void g(const T& t) {
    std::cout << "pass-by-const-ref" << std::endl;
}

template <typename T>
void g(T&& t) {
    std::cout << "pass-by-rvalue-ref" << std::endl;
}

template <typename T>
void f(T&& t) {
    g(std::forward<T>(t));
}


class Test { };
/*
void g(Test& x) {
    std::cout << "Modifiable version of g called\n";
}

void g(const Test& x) {
    std::cout << "Immutable version of g called\n";
}

void g(Test&& x) {
    std::cout << "Move version of g called\n";
}

template <class T>
void f(T&& x) {
    g(x);
}
 * */
int main() {
    
    //What is meant by "forwarding"?
    // Passing a function argument into another function
    
    //What is meant by "perfect forwarding"?
    // passing the argument into another function in the same way it's passed into the first function
    // if arg is mutable, forwarded argument should also be mutable
    // if arg is an rvalue reference, then the forwarded argument should also be an rvalue reference
    
    
    //• What does std::forward() do?
    // if x is an lvalue, std::forward<type_of_x>(x) is also an lvalue
    // otherwise, std::forward<type_of_x>(x) is an rvalue
    
    /*• In the previous set of exercises, you wrote a program which
demonstrated a forwarding reference
• Extend this program by adding a function g() which takes an lvalue
reference and prints out its argument type. Overload g() with a
version that takes an rvalue reference
• Modify the function with the forwarding reference so that it calls the
appropriate overload of g() for its argument
• Test your program and check that it gives the expected results
 * */
    Test x;
    const Test& rx = x;
    f(x);
    f(rx);
    f(Test());
    
    
	return 0;
}
