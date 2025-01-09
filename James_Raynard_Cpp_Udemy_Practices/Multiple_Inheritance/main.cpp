#include <iostream>

class Base_1 {
public:
    void print_base_1() {
        std::cout << "base_1 call" << std::endl;
    }
};


class Base_2 {
public:
    void print_base_2() {
        std::cout << "base_2 call" << std::endl;
    }
};

class Derived : public Base_1, public Base_2 {};

int main() {
    
    //Explain briefly what is meant by multiple inheritance
    // a derived class taking two different classes as base part
	Derived derived;
    derived.print_base_1();
    derived.print_base_2();
    
    /*• What effect does the following code have?
    bool Device::initialize(Params&);
    void TouchResponder::initialize();
    Mouse mouse;
    mouse.initialize();
    */
    // compiler error: ambiguous call on initialize

    
    
    return 0;
}
