#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void foo() const{
        std::cout << "base foo called" << std::endl;
    }
};
class Derived : public Base {
public:
    void foo() const override {
        std::cout << "derived foo called" << std::endl;
    }
};

int main() {
    
    //What does typeid() do? When could it be useful?
    // returns a typeinfo object
    
    //Write a simple program which uses typeid()
    Base base;
    Derived derived;
    Base* pBase = &derived;
    std::cout << "type of pBase's pointed object is " << (typeid(*pBase)).name() << std::endl;
    pBase = dynamic_cast<Derived *>(pBase);
    if (pBase)
        std::cout << "type of pBase's pointed object is " << (typeid(*pBase)).name() << std::endl;
    
    //Briefly describe type_info
    // object that's returned by typeid
    // .name() returns a c-style string 
    // .hash_code() returns a hash integer unique to the type of the stored object's class 
    
    //Write a simple program which uses type_info
    // constructor is deleted, so you can construct it only with typeid
    
    //Briefly describe hash_code
    // above
    
    //• What safety features does dynamic_cast include?
    //• Why are these safety features needed?
    // if casting a pointer fails, returns a nullptr
    // if casting a reference fails, throws std::bad_cast exception
    // we don't want to lose info on the object, so it's best practice to do as dynamic_cast does
    
    /*Write a simple program which uses dynamic_cast with
    • A pointer to the base class
    • A reference to the base class*/
    // pointer to base is above
    Base& rBase = derived;
    try {
        rBase = dynamic_cast<Derived &>(rBase);
    }
    catch (const std::bad_cast& e) {
        std::cout << "bad cast exception: " << e.what() << std::endl;
    }
    
    return 0;
}
