#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include "c_file.c"


int main() {
    
    /*First, write a C function that takes an array of int as argument and displays all the elements in the array. 
     * Store this function in a file with a ".c" extension, so it will be compiled as C and not C++.
    If you are not sure how to do this, you can use the C source code file in the downloadable attachment to these instructions.
    In the main part of this assignment, you will write two C++ programs which use the C interface to call this function.*/
    
    //Write a C++ program which populates an std::set object and uses your C function 
    // to print out all its elements. Check that your program compiles and runs correctly.
    std::set<int> intset {3,1,4,1,5,9};
    std::vector<int> vec;
    std::copy(intset.begin(), intset.end(), back_inserter(vec));
    print_array(vec.data(), vec.size());
    std::cout << std::endl;
    /*Write a C++ program which populates an std::map object and uses your 
     * C function to print out all its elements. Use separate calls to print out the keys of the 
     * map and its values. Check that your program compiles and runs correctly.*/
    std::map<int,int> map;
    // populate the map object
    for (int i=0; i<10; i++) {
        map.insert( std::make_pair(i,i+1) );
    }
    
    // get all items into seperate vectors
    std::vector<int> keys;
    std::vector<int> values;
    
    std::for_each(map.begin(),map.end(), [&keys, &values] (auto el) {
        keys.push_back(el.first);
        values.push_back(el.second);
    });
    
    print_map(keys.data(), values.data(), keys.size());
	return 0;
}
