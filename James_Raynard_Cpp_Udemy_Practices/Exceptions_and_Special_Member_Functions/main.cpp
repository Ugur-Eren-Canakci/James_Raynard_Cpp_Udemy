#include <iostream>


class Obj {
public:
    Obj(int x) {
        std::cout << "constructor called with x=" << x << "\n";
        if (x == 0) {
            std::exception e;
            throw e;
        }
    }
};


int main() {
    
    //What happens if a destructor throws an exception?
    // if the destructor handles the error itself, object can be destroyed
    // otherwise, a stack unwind starts
    // this calls destructors for other objects in the function body where the destructor is called
    // if another destructor throws an exception this starts another concurrent stack unwinding
    // undefined behaviour => could lead to crashes
	
    //What happens if a constructor throws an exception?
    // If it handles the exception itself, then the call finishes and the code in the catch block gets executed
    // otherwise, all data members and subparts are destroyed, and program continues as if the constructed object has never existed
    
    //Is it useful for a constructor to handle exceptions itself?
    // Not really. The object will be half-created and then destroyed, as the object doesn't count as initialized until the whole
    // constructor body is executed without any errors
    
    //Is it useful for a constructor not to handle exceptions itself? 
    // Yes. For example, the constructor might be called with correct arguments so that the same error doesn't appear and 
    // the construction actually would finish. Or, the reason of the error can be returned to the caller, to be fixed inside 
    // the caller itself.
    
    /*• Write a simple class whose constructor throws an exception
    • Write a program which creates an object of this class inside a
    try/catch block which handles this exception
    • Run your program. Compare the results when the constructor throws
    an exception with the results when it does not throw
     * */
    
    try {
        Obj object_1(1);
        Obj object_0(0);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught" << std::endl;
    }
    return 0;
}
