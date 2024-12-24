#include <iostream>
#include <vector>
int main() {
    
    
    //What is meant by "auto" in Modern C++?
    // auto is a type keyword where the compiler is given the responsibility to figure out what type a variable is
    
    //Why is auto important?
    // there are some typenames that are too tedious to figure out or write out
    // lambda functions, for example, create function objects with compiler-generated names. there might be a need to access this class, and auto could
    // be helpful for this
    
    //Write a program which defines variables using "auto". Print out the values of the variables
    auto a {5};
    auto b {5.0};
    auto c {"Hello"};
    auto d {0x16ba};
    std::cout << a << " " << b << " " << c << " " << d << "\n";

    //Use auto to write down a simpler version of the following definition vector<int>::iterator it = vec.begin();
    std::vector<int> vec {1,2,3};
    auto it = vec.begin();

    
    //Write a program which defines a variable which is a reference to const int
    const int e {5};
    auto& f = e; // auto doesn't "pick up" anything but the type
    
    //Using auto, define another variable which is initialized from this variable
    auto g = f;
    std::cout << ++g << std::endl;
	return 0;
}
