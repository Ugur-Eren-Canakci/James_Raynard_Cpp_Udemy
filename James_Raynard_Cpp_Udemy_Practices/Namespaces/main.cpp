#include <iostream>

namespace nsp {
    
    class Temp {
    private:
        int x, y;
    public:
        Temp(int x, int y) : x(x), y(y) {}
    };
    
}

using namespace std;
int main() {
    
    //Briefly explain what is meant by the term "namespace" in C++
    // it's a container for definitions of functions and classes.
    // there cannot be two different definitions of the same name. So, if definitions are done in namespaces, different definitions don't get mixed up
    // you have to add the namespace prefix when you call functions from the namespaces
    
    // functions in the global namespace is called by ::func
    // functions in other namespaces are called by "namespace_name::func"
    // same for classes
    
    // most used namespace is std
    
    
    //Write down code to
    //• Define a namespace
    //• Declare a class inside this namespace
    //• Create an object of this class, outside the namespace
    
    nsp::Temp temp{3,4};
    
    //What is meant by the term "global namespace"?
    //• How do we declare a symbol in the global namespace?
    //• Give an example of how to unambiguously refer to a symbol from the
    //global namespace
    
    // if you didn't define a function/class inside a scope that starts with "namespace namespace_name { ... }", then you defined those in the global namespace
    // chatgpt says: by putting :: before the symbol
    
    //What is meant by "name hiding"?
    // in a new scope, a previously used name can be defined to hold another value, and this value will "hide" the previously defined value until the end of that scope
    //• Write a program which demonstrates name hiding
    //• Add code to your program which makes the outside name accessible
    //within the namespace
    
    //namehiding program
    int x = 10;
    {
        int x = 15;
    }
    
    //second one
    {
        int y = x+3;
        std::cout << y << std::endl;
    }
    
    using nsp::Temp;
    Temp a {3,6};
    
	return 0;
}
