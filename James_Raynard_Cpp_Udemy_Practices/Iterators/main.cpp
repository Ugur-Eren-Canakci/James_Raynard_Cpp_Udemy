#include <iostream>
#include <string>
#include <iterator>
int main() {
    
    //Briefly describe the similarities between an interator to a container element and a pointer to an array element
    // you can dereference an iterator to get the value, but the structure of the value depends on the container iirc
    // also you can use arithmetics on the iterators and run loops to access all elements in a container, for example
    
    //Write a simple program that prints out the elements of an std::string, using an iterator to iterate over the string
    std::string s {"Hello World!"};
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
	return 0;
}
