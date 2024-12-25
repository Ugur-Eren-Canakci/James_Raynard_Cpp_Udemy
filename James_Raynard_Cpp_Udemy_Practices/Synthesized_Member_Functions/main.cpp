#include <iostream>

class Test {
private:
    int x_pos;
    int y_pos;
public:
    void print() {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    
    // Test() {}
    // Test(const Test& other) : x_pos(other.x_pos), y_pos(other.y_pos) {}
    // Test& operator=(const Test& other) {
    //    this->x_pos = other.x_pos;
    //    this->y_pos = other.y_pos;
    //    return *this;
    // }
    // ~Test() {}
}


int main() {
    
    //What is a default constructor?
    // a constructor that can be called with no arguments
    
    //In what circumstances does the compiler synthesize a default constructor?
    // when there's no constructor and no copy constructor definition in the class definition
    
    //What does this synthesized default constructor do?
    // calls the default constructor for each attribute
    
    //In what circumstances does the compiler synthesize a copy constructor?
    // when there's no copy constructor definition in the class definition
    
    //What does this synthesized copy constructor do?
    // calls the copy constructor for each attribute
    
    //In what circumstances does the compiler synthesize an assignment operator?
    // no assignment operator
    
    //What does this synthesized assignment operator do?
    // calls the assignment operator for each attribute
    
    //Write a program which demonstrates the use of synthesized special member functions
    //• Add comments to your program showing the code that the compiler would generate when synthesizing these member functions

    
    
    return 0;
}
