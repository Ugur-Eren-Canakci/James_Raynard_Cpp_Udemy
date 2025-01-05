#include <iostream>


class Test {
private:
    double x, y;
public:
    Test(int x, int y) : x(x), y(y) {
        std::cout << "two arg constructor" << std::endl;
    }
    
    Test() : Test(0,0) {
        std::cout << "no args constructor" << std::endl;
    }
    
    Test(Test&& other) noexcept : x(other.x), y(other.y) {
        std::cout << "move constructor" << std::endl;
    }
    
    Test& operator=(Test&& other) noexcept {
        if (&other != this) {
            x = other.x;
            y = other.y;
        }
        std::cout << "move assignment operator" << std::endl;
        return *this;
    }
    
    ~Test() noexcept {
        std::cout << "destructor" << std::endl;
    }
};
int main() {
    
    /*Modern C++ has two special member functions which are not present
    in traditional C++
    • Describe them briefly*/
	
    // Move constructor takes in an existing (temporary or persistent) object and "moves" its data, as in giving the ownership 
    // of the data in the old object to the target object
    
    // Move assignment operator does the same thing, except when the object is "moved onto itself". If so, this changes nothing
    
    //In what circumstances will the compiler synthesize the move operators?
    // Two conditions:
    // 1) The class doesn't have a copy constructor, copy assignment operator and a destructor
    // 2) The data members are built-in, or types with move operators, or static
    
    //How are these synthesized move operators implemented?
    // The move operators of the data members are called and assigned onto their respective fields
    
    //• If a class implements move operators but not copy operators, will the compiler synthesize the copy operators?
    // There are some objects which are not supposed to be copied. The user-defined object also might be as such. Hence, 
    // I believe that the compiler is not supposed to synthesize copy operators in such circumstances
    // Apparently the compiler synthesizes them as deleted, which is on the same logic with my deduction
    
    //• What is the "Rule of Five"?
    // If you explicitly defined one of copy operators, move operators or destructor, then you should define all five
    
    //Implement a simple move-only class
    //Write a program to test your class. Verify that it cannot be copied
    std::cout << "\ntest_1 construction:\n";
    Test test_1{};
    std::cout << "\ntest_2 construction:\n";
    Test test_2(3,4);
    std::cout << "\ntest_3 construction:\n";
    Test test_3(std::move(test_2));
    std::cout << "\ntest_4 construction:\n";
    Test test_4 = std::move(test_3);
    std::cout << "\nend of main\n";
    //Test test_5(test_4); error: use of deleted function 'constexpr Test::Test(const Test&)'
    //Test test_6 = test_5; error: use of deleted function 'constexpr Test::Test(const Test&)'
    
    return 0;
}
