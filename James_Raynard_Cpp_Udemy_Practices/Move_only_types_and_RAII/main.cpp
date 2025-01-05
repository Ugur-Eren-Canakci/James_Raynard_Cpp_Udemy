#include <iostream>
#include <fstream>

using namespace std;
int main() {
    
    //Give an example of a move-only class in the C++ standard library
    // fstream, iostream, multithreading classes, etc.
    
    //What problems could occur if objects of this class could be copied?
    // if copy operators are not "deleted", two different fstream objects could try to close the same file, which might result in undefined behaviours
    
    //• When a class manages a resource using the RAII idiom, what happens when an object of that class is moved?
    // The resource is now owned by the target object
    
    //How can a lambda expression perform a capture by move?
    // If on C++14 onwards, capture list can define a local variable with the move constructor of that class
    
    //Write a simple program which demonstrates the difference between capture by reference and capture by move
    
    auto lambda1 = [&cout] () {
        cout << "reference capture" << endl;

    };
    auto lambda2 = [lcout = std::move(cout)] () {
        lcout << "move capture" << endl;
        // error: no match for 'operator<<' (operand types are 'const std::basic_ostream<char>' and 'const char [13]')
    };
    return 0;
}
