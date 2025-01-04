#include <iostream>
/* answer to the third question
class Test {
private:
    int x, y;
public:
    Test(Test&& other) noexcept : x(other.x), y(other.y) {
        std::cout << "move constructor" << std::endl;
    }
    
    Test& operator=(Test&& other) noexcept {
        if (&other != this) {
            this->x = other.x;
            this->y = other.y;
            std::cout << "move assignment operator" << std::endl;
        }
        return *this;
    }
};
*/
class MyClass {}; 

class Test {
private:
    int i{0}; // Built-in member
    MyClass m; // Class member
public:
    Test() = default; // Constructor (calls m's constructor)
    
    Test(Test&& other) noexcept : i(other.i), m(std::move(other.m)) { // Move constructor
        std::cout << "Move constructor" << std::endl;
    }
    
    Test& operator=(Test&& other) noexcept {
        
        if (&other != this) {
            std::cout << "Move assignment operator" << std::endl;
            i = other.i;
            m = std::move(other.m);
        }
        return *this;
        
    }
};
int main() {
    
    //What are the names of the move operators?
    // move constructor, move assignment operator
    
    //Briefly explain their purpose
    // Move constructor takes in an rvalue object whose members will be moved to an existing object of same type
    // members of built-in types will be simply copied 
    // members of not-built-in types are lvalues inside the temporary object, so they have to be forwarded with 
    // a std::move wrapper, so that the move constructor for those types can be utilized instead of the copy constructor
    // Exactly the same stuff happens for move assignment operator
	
    //Write down prototypes for the move operators for a class Test
    // Above
    
    //• What differences in syntax are there between move operators and
    //their copy equivalents?
    // argument is non-const since the argument will be seperated from its value
    // move operators get a noexcept signature because there shouldn't be any rollbacks with move operations 
    
    /*• Add copy and move operators to the class "Test"
    • Each operator should print out a message when it is called, to say
    what kind of operator it is
    • Write a program to test your class
    • Explain your results
     * class Test {
    private:
    int i{0}; // Built-in member
    MyClass m; // Class member
    public:
    Test() = default; // Constructor (calls m's constructor)
    };
     * */
    Test test_1;
    Test test_2(std::move(test_1));
    Test test_3 = std::move(test_2);
    
    //When writing a move operator for a derived class, are there any special considerations you should bear in mind?
    // Base part of the moved object will be moved into the base part of the target object
    // => In the move operators, move constructor of the Base class should be invoked (as Base(std::move(arg)) )
    // Derived(Derived&& other) : Base(std::move(other)), ... noexcept {...}
    // Derived& operator=(Derived&& other) {
    //     ...
    //     Base::operator=(std::move(other));
    //     ...
    // }
    
    //What happens if we have a class that was written for an older version of C++ and does not have any move operators?
    // Copy operators will be called 
    
    
    return 0;
}
