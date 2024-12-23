#include <iostream>

int main() {
    
    
    // Write a simple program that creates a pointer
    
    //Use a stack variable to set the pointer's value
    int a {3};
    int* a_ptr = &a;
    
    // Print out the value of the pointer
    std::cout << "address of a: " << a_ptr << std::endl;
    
    //Print out the value of the stack variable by dereferencing the pointer
    std::cout << "value of a: " << *a_ptr << std::endl;
	
    
    //Explain how to obtain allocated memory from the heap
    int* b_ptr = new int; // "new" keyword is used to allocate memory on the heap. return value is a pointer
    int* c_ptr = new int[5]; // we can allocate many memory slots at once, as a dynamic array
    
    // Why are pointers needed for this kind of memory?
    // chatgpt has great answers:
    // 1) Heap memory is allocated dynamically during runtime using functions like new, malloc, or similar. The memory allocation returns the address of the memory block in the heap, and a pointer is required to store this address.
    // 2) Without a pointer, you would not have any way to access or manage the memory since it doesn't have a direct variable name.
    // 3) Unlike stack variables (which are automatically allocated and deallocated when they go out of scope), heap memory must be explicitly managed.
    // 4) Pointers allow you to control the lifetime of objects independently of scope.
    // 5) Pointers allow you to dynamically allocate and manage arrays or other data structures on the heap.
    
    
    //What important thing must you do with this memory when you have finished using it? Why is it important?
    delete b_ptr;
    delete[] c_ptr;
    // heap is permanent. if delete commands are not called, the pointers defined in the stack will be uninitialized, but the values pointed by them won't.
    // hence, that will create a memory leak.
    
    // Explain how to obtain allocated memory from the heap which can be used for an array
    // done above
    
    // Write a simple program which allocates memory from the heap for an array. Populate the array and print out the values of its elements
    int* d_ptr = new int[3];
    
    for (int i=0; i<3; i++) {
        *(d_ptr+i) = i;
    }
    
    for (int i=0; i<3; i++) {
        std::cout << *(d_ptr+i) << " ";
    }
    std::cout << std::endl;
    //What important thing must you do with this memory when you have finished using it? Why is it important?
    delete[] d_ptr;

    
    return 0;
    
}
