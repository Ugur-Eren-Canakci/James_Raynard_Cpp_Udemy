#include <iostream>

class Base {
public:
    template <typename T>
    void func(T& x) {
        x += 1;
    }
};

template <typename T1>
class Derived : public Base {
private:
    T1 x;
public:
    Derived(T1 x) : x(x) {}
    template <typename T2>
    T1 f(T2& y) {
        return x-1;
    } 
};
int main() {
    
    //What is meant by a "member template"?
    // it's a blueprint for a member function, that allows the compiler to write the appropriate member function
    // with the given parameters
    // i.e. it's a member function that utilizes templating
    
    // Write a simple program with a member template
    Base base;
	int x = 3;
    
    base.func<int>(x);
    std::cout << x << std::endl;
    
    //Is it possible for a member template to have a different parameter from its class?
    // Yes
    
    //Write a simple program to demonstrate your answer
    Derived<int> derived(3);
    double y = 10;
    std::cout << derived.f<double>(y) << std::endl;
    
    
    return 0;
}
