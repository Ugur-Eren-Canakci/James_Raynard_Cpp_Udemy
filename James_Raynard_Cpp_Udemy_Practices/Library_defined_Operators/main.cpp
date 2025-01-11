#include <iostream>
#include <functional>

template <typename T, typename Func = std::less<T> >
bool compare(const T& t1, const T& t2, Func f = Func()) { 
    return f(t1,t2);
}


int main() {
    
    //Explain what the following code represents: std::less<T>
    // takes in two objects of the same type, and invokes operator<(obj1, obj2) 
    
    //Which header file is std::less defined in?
    // <functional>
    
    /*• Using the techniques in this lecture
    • Write a non-member function
    • The function compares its first two arguments and returns the result
    • The comparison will use a callable function object which is passed as the third
    argument
    • If no function object is passed, use the < operator of the data members
    instead
    • (Similar to STL algorithms like std::sort)
    • Write a program and test your class
    */
    
    std::cout << std::boolalpha;
    std::cout << compare(3,5) << ", " << compare(5,3);
    
    
    return 0;
}
