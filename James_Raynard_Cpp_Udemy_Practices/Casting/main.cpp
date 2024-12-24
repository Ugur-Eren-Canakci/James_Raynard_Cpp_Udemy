#include <iostream>

void func(int x) {
    
    std::cout << x << std::endl;
}

void func2(double* x) {
    
    *x += 1;
    *x -= 1;
    std::cout << *x << std::endl;
}


int main() {
    
    //What are the four different types of cast in C++? Briefly state what each one does
    
    // static_cast
    // compile-time conversion 
    // useful for converting subclasses into superclasses and vice-versa
    // also used for compatible primitives like char to str or float to int 
    
    // const_cast
    // used to convert const values to non-const ones, when one has to go into a function
    // does not affect the underlying type. only removes/adds const or volatile keywords
    
    // reinterpret_cast
    // used on pass-by-pointer/address situations
    // chatgpt says:
    // It allows you to convert between unrelated types by reinterpreting the underlying 
    // bit pattern, such as casting a pointer of one type to another or converting between 
    // integral types and pointers. This cast provides no guarantees about the validity or 
    // safety of the resulting type, so it must be used with caution.
    
    // dynamic_cast
    // used for "base" pointers pointing to "derived" objects.
    
    //For static_cast and const_cast, write a simple program to demonstrate their use
    
    const double a = 5.0f;
    
    func(static_cast<int>(a));
    
    func2(const_cast<double*>(&a));
    
 
	return 0;
}
