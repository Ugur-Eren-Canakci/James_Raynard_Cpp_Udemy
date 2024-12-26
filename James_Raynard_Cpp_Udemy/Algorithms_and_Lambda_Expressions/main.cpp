#include <iostream>
#include <algorithm>
#include <vector>


class is_shorter {
public:
    bool operator() (const std::string& lhs, const std::string& rhs) {
        return lhs.length() < rhs.length();
    }
};

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
    
	return 0;
}
