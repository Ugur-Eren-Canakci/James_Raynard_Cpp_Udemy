#include <iostream>

class Test {
    int i;
    string str;
public:
    Test(const Test& other) : i(other.i), str(other.str) {}
};

int main() {
    
    //Briefly explain what a copy constructor is
    // Answer: it's a constructor overload that takes in a single argument that's a const reference to an existing object of the same class

    // How is the copy constructor invoked?
    // assume Test test1 already exists. 
    // Test test2{test1};
    // Test test3 = test1;
    // both calls above invokes the copy constructor
    
    //Explain why it is not normally necessary to implement a copy constructor when writing a class
    // The compiler creates one for us if we don't define one
    // It copies all attribute values onto the new object
    
    //In what circumstances is it necessary to implement a copy constructor?
    // When there's necessary resource management such as heap allocation, unique identifiers, database connections, etc.

    //Write an example of the code that the compiler could generate when synthesizing a copy constructor
    // Answer: above
    return 0;
}
