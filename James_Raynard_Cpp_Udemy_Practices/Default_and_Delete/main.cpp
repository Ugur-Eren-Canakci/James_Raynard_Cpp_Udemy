#include <iostream>

//Write a simple class which cannot be copied or assigned to
//• Using Traditional C++ features
//• Using Modern C++ features

class Test1 { //traditional hiding
private:
    int i;
    Test1(const Test1& other) = default;
    Test1& operator=(const Test1& other) {
        this->i = other.i;
        return *this;
    }
public:
    Test1() = default;
    ~Test1() = default;
};

class Test2 { //modern hiding
private:
    int i;
    
public:
    Test2() = default;
    Test2(const Test2& other) = delete;
    Test2& operator=(const Test2& other) = delete;
    ~Test2() = default;
};
int main() {
    
    //• What does the "default" keyword do?
    // forces the compiler to synthesise the function the "= default" is put onto.
    
    //Why is it useful?
    // 1) easier to see which special methods the class has
    // 2) documents that a method has been deliberately defaulted
    // 3) avoids tedious code writing
    // ***4) If data members are added or removed, then the compiler will automatically update the definition
    
    //Can it be used with non-member functions?
    // "default" means nothing for a standalone function. so, no
    
    //What does the "delete" keyword do?
    // makes a method uncallable 
    
    //Why is it useful?
    // If you don't want an object type to be copied, or
    // If you don't want a specific constructor to be used
    // You can add "= delete" to these to make them not usable
    
    //• Can it be used with non-member functions?
    // Yep
    
    /*Test1 test1;
    Test1 test2{test1};
    */
    /*Test2 test1;
    Test2 test2{test1};
    */
    
	return 0;
}
