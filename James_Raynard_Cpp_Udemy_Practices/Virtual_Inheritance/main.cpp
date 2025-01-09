#include <iostream>

class Base {};
class Left : public virtual Base {};
class Right : public virtual Base {};
class Derived : public Left, public Right {};

int main() {
    
    //What is virtual inheritance and why is it useful?
    // when you want to inherit multiple classes that share a base class inheritance
    // if defined as usual, the derived class will have two separate parts of the same base class, which is not ideal
    
    //Write a simple program which uses virtual inheritance
    // class definitions above
    
	return 0;
}
