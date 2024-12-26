#include <iostream>
#include <vector>
#include <string>
#include <iterator>

int main() {
    
    //Briefly explain what an insert iterator is and how it is used
    // used to populate containers without having overflow/invalid iterator issues
    
    //How can we obtain an insert iterator for a container object?
    // by calling one of back_inserter(), front_inserter() or inserter() with the container as the argument
    // inserter takes a second argument, which is the position in the container we want to put an item at.
    
    // Briefly explain what back_insert_iterator does
    // cppreference:
    // The container's push_back() member function is called whenever the iterator 
    // (whether dereferenced or not) is assigned to. Incrementing the std::back_insert_iterator is a no-op.
    
    //Write a simple program which demonstrates the use of a back_insert_iterator
    std::vector<int> vec;
    auto it = back_inserter(vec);
    for (int i=0; i<10; i++) {
        it = i;
    }
    for (auto el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    
    
    
    
    return 0;
}
