#include <iostream>
#include <memory>


class Test {
public:
    double x, y;

    Test(double x, double y) : x(x), y(y) {
        std::cout << "two args constructor called" << std::endl;
    }
    
    Test() : Test(0.0,0.0) {
        std::cout << "no args constructor called" << std::endl;
    }
};

void func(std::unique_ptr<Test> test_ptr) {
    std::cout << test_ptr->x << ", " << test_ptr->y << std::endl;
}

std::unique_ptr<Test> ptr_func(int x, int y) {
    std::unique_ptr<Test> res {new Test(x,y)};
    return res;
}
int main() {
    
    //Briefly describe how std::unique_ptr is implemented
    // has a private pointer member 
    // type of the pointer is decided by template parameters
    // can point to a single variable or an array
    // if pointed to an array, will point to the first element of the array
    // constructor allocates the memory, and destructor releases the memory
    
    //In terms of memory usage and efficiency, how does unique_ptr compare to traditional pointers?
    // In pure efficiency terms, raw pointers are better since unique_ptr contains one raw pointer member
    // otherwise, the overhead is not too much as special members are common to all objects
    
    //Explain how unique_ptr follows the principles of RAII
    // unique_ptr cannot be copied, as if it were allowed to be copied, then you would have non-unique pointers,
    // and if we were to call delete on one of the copies then all other copies would have a dangling raw pointer inside.
    // constructor allocates the memory in the heap with "new", destructor releases the memory
    // hence, every object commits to a resource allocation when initialized (RAII)
    
    //Write a simple program that creates and initializes a unique_ptr object and performs some operations on it
    auto ptr = std::unique_ptr<Test>({new Test()});
    std::cout << ptr->x << ", " << ptr->y << std::endl;
    
    //How can a unique_ptr be passed as a function argument?
    // unique_ptr objects cannot be copied, and the value it holds is unique to the owner. Hence, the value 
    // has to be moved to the function argument
    func(std::move(ptr));
    ptr = nullptr;
    
    //What happens when a unique_ptr is returned from a function?
    // The return object is constructed inside the function's return space, and
    // if a variable is assigned with that function, the object is moved from the return space to the variable.
    
    //What are the advantages of returning unique_ptr instead of a traditional pointer?
    // It doesn't make sense to point to a function's local variable and return its pointer, as the local variable will be destroyed.
    // So, the initialized object is always in the heap. Returning a raw pointer allows for a potential memory leak if the programmer
    // forgets to call "delete" on the raw pointer
    
    //Write a function which creates a unique_ptr local variable which is returned by the function
    auto p = ptr_func(4,6);
    std::cout << p->x << ", " << p->y << std::endl;
    
    
	return 0;
}
