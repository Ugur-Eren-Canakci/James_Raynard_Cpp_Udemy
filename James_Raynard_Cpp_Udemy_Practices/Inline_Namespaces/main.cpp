#include <iostream>

namespace A {
    namespace B {
        int x;
    }
    inline namespace C {
        int y = 5;
    }
};
    

int main() {
    
    //What is meant by a "nested namespace"?
    // you can place namespaces inside namespaces
    /*Write a simple program which defines a nested namespace
    • Inside the nested namespace, define a symbol
    • Access this symbol from main()
     * */
    A::B::x = 4;
    using namespace A;
    std::cout << B::x << std::endl;

    //What is meant by an "inline namespace"?
    // a namespace that forwards its variables and definitions to the namespace that contains it
    // if a namespace isn't contained by any namespaces, it's contained by the global namespace
    
    //Write the same program as in the last exercise, but this time using an inline namespace instead of a nested namespace
    std::cout << y << std::endl;
	return 0;
}
