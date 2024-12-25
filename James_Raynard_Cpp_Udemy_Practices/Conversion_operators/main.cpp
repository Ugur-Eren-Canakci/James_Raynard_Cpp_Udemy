#include <iostream>

class Test {
private:
    int x;
public:
    explicit Test(int x) : x(x) {
        std::cout << "Constructor called" << std::endl;
    }
    
    explicit operator int() {
        return x;
    }
        
};

int main() {
    
    //What is a conversion operator?
    // can see in Test definition
    // overload of the typename keywords

    //What is meant by an implicit conversion?
    // When incompatible types are put into functions or operations, the compiler will look for ways to interpret the statements
    // If there's no overload that works for a specific statement, then the compiler tries to convert variables into suitable format for that operation
    // this is done implicitly, i.e. not by the written code, but by the compiler
    // and this is called implicit conversion
    
    //• What is meant by an explicit conversion?
    // the explicit call of casting
    
    //• It is possible to prevent implicit conversions?
    // yes, by the keyword "explicit"
    
    //Are there any exceptions to this?
    // yes, conditional statements
    
    //How can implicit conversion of a class object be prevented?
    // by putting "explicit" before the conversion overload
    
	return 0;
}
