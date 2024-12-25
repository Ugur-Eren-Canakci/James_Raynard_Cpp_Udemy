#include <iostream>
#include <vector>


class Internet {
public:
    void connect() {
        std::cout << "Connected to internet\n";
    }
    void login(const std::string& id, const std::string& pw) {
        std::cout << "Logged in with username " << id << " and password " << pw << "." << std::endl;
    }
};

class refrigerator {
private:
    int temperature{2};
    bool door_open{false};
    bool power_on{true};
    Internet internet;
public:
    
    refrigerator() { // default constructor
        // before the brackets we could put " : refrigerator(2, "me", "secret")
        // this would've called the no-defaults constructor in calling this constructor,
        internet.connect();
        internet.login("me", "secret");
    }
    
    refrigerator(int temperature) : temperature(temperature) {
        internet.connect();
        internet.login("me", "secret");
    }
    
    refrigerator(const std::string& id, const std::string& pw) {
        internet.connect();
        internet.login(id, pw);
    }
    
    refrigerator(int temperature, const std::string& id, const std::string& pw) 
        : temperature(temperature) { // no defaults constructor
            internet.connect();
            internet.login(id, pw);
    }
    void print() {
        std::cout << "temperature = " << this->temperature << std::endl;
        std::cout << std::boolalpha;
        std::cout << "door open = " << this->door_open << std::endl;
        std::cout << "power on = " << this->power_on << std::endl;
    }
};



class evenp { // functor
public:
    bool operator() (int n) {
        return (n%2 == 0);
    }
};


void do_it(const std::vector<int> vec, evenp is_even) {
    for (auto el : vec) {
        if (is_even(el)) {
            std::cout << el << " is even." << std::endl;
        }
        else {
            std::cout << el << " is odd." << std::endl;
        }
    }
}


int main() {
    
    //Constructors
    
    // Data members are default-initializedoddif not set in the constructor
    // For built-in types, this means the initial value is undefined/garbage value
    // For example, boolean values have 50/50 likelihood of being true or false
    
    // You can set up a default constructor that initializes the attributes from user input, or declare the constructor with default values
    
    // C++ allows us to initialize the attributes in the class definition
    
    // you can call an existing constructor in other constructor overloads
    
    
    
    // Copy constructors
    
    // Specialized version of the constructor
    // Takes only one argument, that is an object of the same class
    // That argument is passed by (const) reference
    
    // Automatically called when initializing an object from another one
    // Ex:
    // Test test1 {some_argument, some_argument};
    // Test test2{test1}; -> copy constructor called 
    // Test test3 = test1
    
    //********IMPORTANT*******
    // Copy constructors can also be invoked in function calls
    
    // Ex: when we have a pass-by-value function, the passed object is copied onto a new object on the function's stack.
    // Hence its copy constructor is called
    
    // Ex: when we return a local variable by value
    // the scope will end, and the original object will be destructed. Hence, its copy constructor is called to create a copy of that object
    // in the stack where the return value appears
    
    // However, compilers can perform optimizations which reduce the amount of copying in function calls, to not call the copy constructor every time
    //*************************
    
    // If we don't implement a copy constructor, the compiler will "synthesize" one for us
    // It will copy all attribute values to the new object
    // Usually this is good enough
    // No need to write one if you don't need specific things to be done on each copy
    // Ex: If you have a pointer to a dynamic array in the heap, you have to allocate a new dynamic array for the new object
    // If the original object is destructed and the copy takes on the exact same pointer with the original one, then 
    // the pointer of the copy will still point to the old position of the array (which has been deleted in the heap), leading to 
    // undefined behaviour
    
    
    // Assignment operator
    
    // operator= is a member function
    // It's invoked when we assign two objects of the class
    // Ex: y = z; (y.operator=(z);)
    // After this statement has been executed, the members of y will have the same values as those of z
    
    // takes in one argument, and it's a const reference to an existing object
    // It returns the modified object by reference(return *this)
    // This allows for chain assignment
    
    // the return value is not const
    // occasionally it's desirable to modify the return value
    // STL containers require non-const return. If returned const reference, the code will not compile
    
    // Test& Test::operator=(const Test& other) {...; return *this;}
    
    // Recall: methods have a secret "this" argument passed in
    
    // If not defined, the compiler will synthesize one for us
    // You have to define it if there's resource management
    
    
    // Synthesized methods
    
    // For the methods below, compiler will synthesize one if we don't declare/define one 
    // Constructor, copy constructor, assignment operator, destructor, and some new methods for move operations
    
    // no constructor + no copy constructor 
    // => default constructor from compiler
    // takes no argument
    // calls the default constructor for each attribute
    
    // no copy constructor
    // => copy constructor from compiler
    // calls the copy constructor for each attribute
    
    // no assignment operator
    // => assignment operator from compiler
    // calls the assignment operator for each attribute
    
    // no destructor
    // => destructor from compiler
    // does nothing as destructors for attributes are automatically called

    
    // Shallow vs. Deep copying
    
    // When there's manual resource management, compiler-generated special member functions are problematic
    // Recall that when a scope ends, the objects in it are released/deconstructed
    // If you do shallow copying in the copy-constructor and assignment operators and the destructor releases memory in the heap, then 
    // the copied object will lose the access to those values, but the copied pointers will stay in. These pointers will "dangle" and 
    // point to nothing 
    
    // Copy constructor should acquire new resource (RAII) and copy the values into this new resource from the copied object

    // Assignment operator should check if one object is assigned onto itself.
    // This is not very likely to appear in daily coding, but can be called. So, we have to be prepared
    // If one object is assigned to itself, then operator= shouldn't do anything
    // Otherwise, operator= should allocate new memory and copy the content from the old object (which's in the heap) and 
    // paste it into the newly allocated memory blocks
    
    // check the equality by:
    // if (&other != this)
    // "this" is a pointer to the current object, so it holds the address of the current object
    // it it's equal to &other, then &other is the address the current object "resides in". Hence, they're equal
    // you don't have to overload operator== for this 
    
    // Rule of three
    // If a class needs to implement one of copy constructor, assignment operator or destructor, then it probably needs to implement the other two as well
    // the default constructor is not in the three since you usually need to implement it in all cases
    
    // If we implement a default constructor that takes in an argument, then the compiler will not synthesise a default constructor
    
    
    // Copy elision
    // The compiler is allowed to skip over a call to the copy constructor in some cases
    // this usually occurs when copying temp variables during function calls
    // this applies even if the copy constructor has side effects
    
    // modern compilers will always apply copy elision if they can
    // most compilers offer an option to disable it -> -fno-elide-constructors
    // for Visual C++ it requires disabling all optimizations -> /Od
    
    // Return value optimization is when the copy of a returned temporary object is elided
    // Ex: say a function has "return Test()".
    // Without elision, a Test object is created, copied onto the return space (just another block of memory to hold the return value), and then the 
    // original object is deconstructed
    // With elision, the initialization is done on the return space itself
    // Elision avoids one copy constructor call and one destructor call

    // A similar process occurs when a local variable is returned by value
    // Ex:
    // Test func2() {
    //    Test test;
    //    return test;
    // }
    // This is called "named return value optimization"
    // Harder for compilers to do than for temp variables
    // May not be done in all cases
    
    // Copy elision also happens when a temp object is passed by value
    
    
    
    // Conversion operators
    // A class can define a conversion operator
    
    // Ex: assume a Test object has int i as an attribute
    // operator int() { return i }
    // since "this" is passed into this function and we're working strictly on the current object, there's no argument
    
    // int x = test + 5;
    // for the code above, the compiler first looks for an operator+ definition between Test and int objects
    // if there's no such operator+, then the compiler searches for implicit conversion
    // operator int() we called works for this case
    
    // implicit conversions usually have undesirable results
    // Ex:
    // int i = 99;
    // cin << i;
    // we don't insert anything into cin, but this code works since:
    // streams have an operator bool() used to check the system
    // cin is implicitly converted to bool
    // the result is then coerced to int
    // the non-overloaded operator<< (ancient C operator for bit shifting) is called for int
    
    // to stop the implicit conversions, you can put "explicit" keyword in front of conversion operators
    // explicit operator int() {return i;}
    // this has one exception, that is, using a variable with overloaded conversion operator in a conditional statement
    
    // A constructor with a single argument acts as an implicit conversion operator
    // To stop this, put "explicit" in front of such constructors
    // Ex: Assume Test class has an int attribute i.
    // Test(int i) : i(i) {} -> constructor with single argument
    // int x = 5;
    // Test test(x); -> 
    // Compiler will create a temporary test object. Then it will use a copy constructor to copy the value of the temporary object into test itself
    // If you use "explicit" on this constructor, then you must explicitly create the objects
    // Ex:
    // explicit Test(int i) : i(i) {} 
    // Test test = 4; -> Error: conversion required
    // Test test = Test(4); -> Works
    
    
    //Default and delete
    
    // modern c++ allows programmers to force the compiler to synthesize special member functions
    // this is done by putting "= default" after the function parameter list
    
    // in modern c++, the compiler may not always synthesize a copy constructor
    
    // advantages of using default:
    // 1) easier to see which special methods the class has
    // 2) documents that a method has been deliberately defaulted
    // 3) avoids tedious code writing
    // 4) If data members are added or removed, then the compiler will automatically update the definition
    
    // Sometimes it's useful to prevent a class from being copied. This is traditionally done by making the copy constructor and the
    // assignment operator to private.
    // In modern c++, we can put "= delete" after the function parameter list
    // This effectively "deletes" these functions
    
    // Deleted functions are defined but not callable
    // Unlike "= default", any function can be "deleted", even non-member ones. However, mostly used for copy operators and default constructors
    
    // If you "delete" the default constructor you cannot default create any objects
    // This forces users to use constructors with arguments
    
    // Sometimes the compiler is not able to synthesise the default constructor and copy operators with "= default"
    // Usually this is when the class has an attribute that doesn't support it
    // Recall: default constructor calls the default constructors of the attributes
    // Also if the class has a member whose destructor is deleted or inaccessible
    // => This prevents the creation of objects that cannot be destroyed
    
    // If the default version doesn't work, they will be synthesised with "= delete"
    
    
    // "Friend" keyword
    
    // To avoid "friend", we can create a member fn which implements the functionality of the operator
    // This member function has direct access to all members of the class
    // The non-member function then calls this member function 
    
    
    //operator<
    
    // <algorithm> provides the "sort" function
    // takes in iterators of a containers
    // compares pointed elements with operator<
    // hence requires an overload for the type of object you want to store in the container
    
    
    
    // prefix and postfix operators
    // ++, -- 
    
    // ++p is equivalent to:
    // p += 1; p;
    //increments the variable and uses it
    
    // p++ is equivalent to:
    // temp = p; p+= 1; temp;
    // uses the variable as is, and after that does the increment
    
    // with postfix operators, we can use the value, and increment it at the same time
    int x {3};
    std::cout << x++ << x << std::endl; // 34
    
    // *p++ -> increment is performed first due to operator precedence (++ has higher precedence than *)
    
    // using postfix increment in loops actually creates another variable
    // compilers usually optimize this
    
    // incrementation in for loops is always at the end of one loop
    
    // prefix overloading:
    /* Test& operator++() { -> returns reference 
     *     ++member;
     *     return *this;
     * } 
     * */
     
     // postfix overloading: (returns a copy of the original object, hence the return type is not a reference, but a value)
     /* Test operator++(int t) { -> t is a dummy argument, to discriminate postfix overload from prefix overload
      *     Test temp(*this);
      *     ++member;
      *     return temp;
      * }
      * */
      
    
    
    
    // operator()
    
    // procedural programming involves a sequence of commands
    
    // functional programming involves a tree of function calls which transform data
    //e.g. processing a vector
    //e.g. function which processes an element
    // e.g. function which "applies" that function to each element

    // callable objects are used to implement functional programming in C++
    
    // A C++ class which implements a function call operator is called a "functor"
    
    // prototype:
    // some_type operator() (arg_list) {...} -> can take any number of arguments and return anything
    
    //Ex:
    evenp is_even;
    std::cout << std::boolalpha << is_even(6) << std::endl;
    
    std::vector<int> vec {1,4,9,16,25};
    do_it(vec,is_even);
    
    // functors are classes, so they could contain member functions and data members
    // to keep things simple and concise, these classes should just be wrappers of a function
    // however, there could be some "state" variables that record some info
    // ex: say you have a bool returning function. keep two members that count how many true's and how many false's are returned
    // instructor ex: if you have a function that generates a sequence number, you can have a static counter
    // for the whole class so that you know how many times the function was called
    
    
    
    return 0;
}
