#include <iostream>

class Test {
private:
    int x_pos;
    int y_pos;
public:
    Test(int x, int y) // constructor
        : x_pos(x), y_pos(y) {}
    
    Test(const Test& rhs) // copy constructor
        : x_pos(rhs.x_pos), y_pos(rhs.y_pos) {}
    
    Test& operator=(const Test& rhs) { // copy assignment
        this->x_pos = rhs.x_pos;
        this->y_pos = rhs.y_pos;
        return *this;
    }

    ~Test() {} // destructor
};

int main() {

    //Briefly describe the purpose of the special member functions:
    //Constructor
    
    // Constructor is the function that is called when an object is initialized.
    // Can be overloaded for different sets of arguments to be supplied by the users
    
    //Copy constructor
    // Used when a new object is created from an existing object, such as a function with one pass-by-value argument
    
    //Assignment operator
    // Assigns values from an existing object to a new object
    // returns *this so that chain assignment is possible
    
    //Destructor
    // Calls when an object is destructed, releases allocated memory, and possibly other stuff
    
    
    
	return 0;
}
