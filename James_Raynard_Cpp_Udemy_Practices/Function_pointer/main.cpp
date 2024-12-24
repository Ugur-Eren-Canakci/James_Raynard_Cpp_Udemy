#include <iostream>

void func(int x, int y) {
    std::cout << x+y << std::endl;
}

//Write down an alias to the type of func_ptr
using f_int = void(*)(int,int);

f_int ptr_fn(f_int ptr) {
    return ptr;
}

int main() {
    
    
    //What is a function pointer?
    // a variable that points to the memory where a function's commands are kept
    // can be dereferenced, and so can call the function it points to
    
    //Write down the definition of a pointer to the following function
    //void func(int, int);
	
    void (*func_ptr)(int,int) = &func;
    
    (*func_ptr)(3,5);
    
    //Write down an alias to the type of func_ptr
    f_int f_ptr = &func;
    (*f_ptr)(4,7);
    
    //Explain briefly what is meant by "callable object"
    // a callable object is an object that's possible to invoke by different means
    
    //• Write a simple program with
    //• A function which returns a function pointer
    //• A function which takes a function pointer as an argument
    //• A main() function which calls both these functions

    return 0;
}
