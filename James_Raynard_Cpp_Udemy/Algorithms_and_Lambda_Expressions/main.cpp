#include <iostream>
#include <algorithm>
#include <vector>


class is_shorter {
public:
    bool operator() (const std::string& lhs, const std::string& rhs) {
        return lhs.length() < rhs.length();
    }
};


class ge_n {
private:
    const unsigned int n;
public:
    ge_n(int n) : n(n) {}
    bool operator() (const std::string& s) {
        return !(s.length() < n);
    }
};


auto greeter(const std::string& salutation) {
    return [salutation] (const std::string& name) {return salutation + ", " + name;};
}

int main() {
    
    // Generic algorithms
    
    // STL algorithms are global functions which will work with any kind of STL container
    // The elements of the containers can also be any type desired
    // These algorithms are known as "generic" algorithms
    
    // Typically, an STL algorithm is passed an ITERATOR RANGE
    // The algorithm will iterate over this range of elements and call a function on each element
    // The algorithm will return either
    // 1) an iterator representing a particular element
    // 2) a value containing the result of some operation on the elements
    
    // Ex: std::find() returns an iterator
    // (Some containers don't have a concept of index) 
    // If the element is not found, then the algorithm will return the iterator for the "one after last" element, i.e. container.end()
    


    // Predicates
    
    // Many algorithms call a function on each element which returns bool
    // Ex: find() calls the operator== for each element to compare it to the target value
    // This is also known as "predicate"
    
    // These algorithms allow us to supply our own predicate
    // We can pass a callable object as an extra argument to the algorithm call
    
    // Ex: std::sort() works by comparing pairs of elements with operator<
    // by a clever choice of which pairs to compare, you make the algorithm much faster
    
    // Ex:
    std::vector<std::string> names = {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};
    
    sort(names.begin(), names.end()); // sorts elements by alphabetic order
    for (auto el : names) {
        std::cout << el << ",";
    }
    std::cout << std::endl;
    
    is_shorter pred;
    sort(names.begin(), names.end(), pred); // sorts elements by length
    for (auto el : names) {
        std::cout << el << ",";
    }
    std::cout << std::endl;
    
    
    
    // Algorithms with "_if" versions
    
    // many algorithms have two versions:
    // 1) base version which takes a value argument
    // 2) an "_if" version which takes a predicate argument
    
    //Ex:
    // find() takes a value and searches for the first element with this value
    // find_if() takes a predicate and returns the first element that returns true from the predicate
    
    // count how many elements have length >= 3
    std::cout << std::count_if(names.cbegin(), names.cend(), ge_n{3}) << " elements have length >= 3." << std::endl; 
    
    
    
    // Lambda expressions
    
    // When the compiler encounters a lambda expression, it will generate code that defines a functor
    // This functor will have a unique compiler-generated name 
    // The function call operator of the functor will have the same body as the lambda expression
    // The function call operator will have the same return type as the lambda expression
    
    // Lambdas are anonymous and defined in-line
    // syntax: [capture_list_here] ( argument_list_here) -> return_type_here { function body here }
    // the return type of the lambda expression will be found by the compiler
    // on c++14, all return statements had to return the same type 
    // on c++17, this is no longer required
    
    // std::equal(cont1.begin(), cont1.end(),cont2.begin(), cont2.end(), binary_predicate)
    // without binary_predicate, std::equal compares each element of the two containers and returns false immediately 
    // if there's a pair that returns false from operator==
    
    // Capture list
    
    // a lambda expression has access to non-local variables and static variables in the same scope
    
    // by default, lambda expressions have very limited access to local variables
    // 1) it can access local variables which are references, and were initialized with a constant expression
    // 2) it can read, but not modify, local variables which are integers or enums and were initialized with constant expression
    // compilers often don't implement this properly

    // if a lambda needs full access to local variables, it can "capture them"
    // this is done by putting the local variables inside []
    
    // this is implemented as "a functor with state"
    // functor has private data members which are from the capture list
    // these are initialized in the functor's constructor
    // the data member is available in the operator()'s function body because operator() is a member function
    
    // by default, the captured variable is passed into the functor's constructor by VALUE  
    // i.e. "capture by value"
    
    // by default, the data members are const
    // operator() cannot modify its copy of the variables
    // if you want to change these copies, add "mutable" after the lambda expression signature
    
    //Ex:
    unsigned int str_length = 6;
    int count = 0;
    std::cout << std::count_if( names.begin(), names.end(), [str_length, count] (const std::string& s) mutable { count++; return s.length() > str_length; } );
    std::cout << std::endl;
    
    // Capture by reference
    // If you want to change a local variable with a lambda expression, you have to capture that variable by reference
    // [&n] ... {n++; ... } -> increases n by 1 outside its scope
    
    // You can set the default capture mode by putting "=" or "&" as the first element of the capture list
    // if you put "=", default captures will be done by value
    // if you put "&", default captures will be done by reference
    // if you don't put any other element after the default caption identifier, then all local variables will be captured 
    // if you need one variable to be captured differently, then you have to explicitly write it down
    
    // int x, y, z, t, p, q, r;
    // [&, =x, =y] ... 
    
    // Recall: all member functions have a secret argument "this", that is the address of the object they are going to be called from
    // "this" in effect is a variable in the scope of the member function
    // when we have a lambda expression in a member function, it's allowed to capture "this"
    // this allows the lambda expression to access data members and call other member functions of the class
    // to capture "this", you can 
    // 1) put "this" in the capture list
    // 2) put a default capture argument(= or &) into the list
    // &this or =this is not allowed
    
    // you can call a lambda function by putting () after its function body
    
    // in C++17 you can put "*this" into the capture list
    // this would capture the current object by value, i.e. copying it
    // the copy is immutable by default, so add mutable if you want to change the copy
    
    
    // Ex:
    int x{42}, y{99}, z{0};
    auto lam = [=,&z]() mutable { ++x; ++y; z = x + y; };
    // x and y will go into the functor's private section as integers
    // z will go into the functor's private section as a reference to an integer

    lam();
    // x and y members of the function object will increment and their sum will be put into z
    // m_x=43, m_y=100, z = 143
    // x = 42, y = 99 
    std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;
    
    lam();
    // x and y members of the function object will increment and their sum will be put into z
    // m_x = 44, m_y = 101, z = 145
    // x = 42, y = 99
    std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;
    
    
    
    // Lambdas and Partial Evaluation
    
    // lambdas are class objects. so, it's possible to store them in a variable to later use operator() on them
    // to store them you need "auto" type variables since the class is compiler-generated, hence we don't have direct access to the name of the class
    
    // we can also return lambda expressions from a function
    auto hello_greeter = greeter("Hello");
    std::cout << hello_greeter("Ugur");
    
    
    // Partial evaluation
    // technique from functional programming
    // data is evaluated in stages
    // Ex: while reading a 700 page document, the pages will be rendered as the reader looks onto one

    // we can use lambda expressions with capture to implement partial evaluation
    // Ex: above, we created hello_greeter to be a function that returns a string starting with "Hello"
    // and adding the argument it's called with to the end of the returned string
    // Hence, when we call greeter, it performs a partial evaluation

    //********IMPORTANT*************
    // Reference to a local variable is dangerous:
    // int& func() {
    //    int x{7};
    //    return x;
    // } -> x is destroyed when function returns, since the scope has finished. 
    // Hence, if a variable is initiated with this function, that variable will be a reference to nothing
    // This might cause the program to crash
    
    // If you're using capture by reference, make sure that the captured variables are valid when you call the lambda.
    
    
    
    return 0;
}
