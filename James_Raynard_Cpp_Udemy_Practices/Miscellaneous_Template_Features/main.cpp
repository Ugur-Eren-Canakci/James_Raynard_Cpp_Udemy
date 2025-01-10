#include <iostream>

constexpr int x = 0;
static_assert( x==0 , "x cannot be 0");

template <typename T1 = int>
class Base {
public:
    T1 x;
    void func() {
        std::cout << "Base func call" << std::endl;
    }
    Base(T1 t) : x(t) {
        std::cout << "constructor call" << std::endl;
    }
    
    template <typename T2>
    void temp_func(T2 x) {
        std::cout << "member template instantiated" << std::endl;
    }
};

int main() {
    
    //Describe static_assert()
    // takes in a bool constexpr and a string literal
    // if bool returns false, compile is stopped, and an error message pops up with the string literal
    // otherwise, continues compiling as usual

    // Write some code to demonstrate the use of static_assert()
    // in the header, change == to !=
    
    /*Write a template class with a default type parameter
    • Write a program which uses your class
    */
    Base base(3);
    
    /*Write a member template with a default type parameter
    • Write a program which uses your class
    */
    base.temp_func(5);

	return 0;
}
