#include <iostream>
#include <functional>

using namespace std::placeholders;

class Base {
public:
    void func() {
        std::cout << "function call" << std::endl;
    }
    
    bool bool_func() {
        return true;
    }
    
    bool bind_match(bool b1, bool b2) {
        return b1 == b2;
    }
};

class Base_functor {
private:
    Base b;
    void (Base::*func_ptr)() = &Base::func;
public:
    void operator() () {
        (b.*func_ptr)();
    }
};


int main() {
    
    /*Define a class with a public member function
    • Write a program which calls the member function through a pointer
    to the member function
    */
    Base base;
    Base* base_ptr = new Base;
    auto p1 = &Base::func;
    void (Base::*p2)() = &Base::func;
    
    (base.*p1) ();
    (base_ptr->*p2) ();
    
    delete base_ptr;

    /*Modify your program so that it converts the member function pointer
    to a callable object*/  
    
    Base_functor callable;
    callable();
     /*Rewrite the std::bind() example from the last video to use a bound
    member function pointer*/
    
    auto match = std::bind(&Base::bind_match, &base, _1, true);
    std::cout << std::boolalpha;
    std::cout << match(true) << " " << match(false) << std::endl;
    
	return 0;
}
