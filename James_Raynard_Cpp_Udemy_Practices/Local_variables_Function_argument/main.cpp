#include <iostream>

void pass_by_value(int x) {
    x++; // increment is done to the copy of x
    std::cout << "pass by value->" << x << std::endl;
    std::cout << "address of the variable->" << &x << std::endl;
}

void pass_by_address(int* int_ptr) {
    std::cout << "pass by address->" << *int_ptr << std::endl;
}

void pass_by_reference(int& x) {
    x++;
    std::cout << "pass by reference->" << x << std::endl;
    std::cout << "address of the variable->" << &x << std::endl;
}

int main() {
    
    // explain what is meant by "local variable" in C++
    // a local variable is a variable that's available in a specific scope. 
    // any subscope, i.e. new scope that's initialized in an existing scope, can access to its superscope's variables
    {
        int x = 5;
        {
            int y = ++x;
            std::cout << y << " is local to the current scope." << std::endl;
        }
        std::cout << "y is not available here. x is equal to " << x << std::endl;
    }
    // std::cout << x << std::endl; -> error: 'x' was not declared in this scope
    
    
    
    
    
    
    // In the following code, what's the initial value of d?
    double d; // garbage value; memory is allocated for d, but a value is not attained. so, if there's a prior value in that memory address, it will be accessed through d
    std::cout << d << std::endl;
    
    
    int e {13};
    
    //Explain what's meant by the following terms:
    
    // pass-by-value
    // a function that has a pass-by-value argument will copy what's placed into that argument and use the copy for the operations it holds
    pass_by_value(e); // e copied and forwarded into the function
    std::cout << "original variable->" << e << std::endl;
    
    // pass-by-address
    // a function that has a pass-by-address argument will take in an address as the argument. 
    pass_by_address(&e); // takes in the address of e, and executes the commands
    
    // pass-by-reference
    // a function that has a pass-by-reference argument will do its operations on the actual value of the variable it's given as the argument
    pass_by_reference(e);
    
    //Add code to your programs to show the addresses of the variables involved
    std::cout << "address of e->" << &e << std::endl;

    
    
	return 0;
}
