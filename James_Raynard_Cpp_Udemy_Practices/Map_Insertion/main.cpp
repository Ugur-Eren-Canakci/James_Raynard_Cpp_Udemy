#include <iostream>
#include <map>
int main() {
    
    //Briefly explain how std::map's operator [] provides "insert or assign" functionality
    // first, it initializes a pair whose first element is between the brackets
    // second, the second element of pair is default-initialized
    // third, the value is assigned to the default-initialized element of the pair
    // finally, the pair is placed into the tree structure
    
    //Are there any drawbacks to using operator [] to insert elements?
    // only built-in types and default-constructible objects can be placed with this method
    
    //Does the insert() member function suffer from these drawbacks?
    // Nope
    // if an element with the same key is already in the map, insert returns a pair
    // whose first member is the iterator pointing to the already existing element of the map
    // and whose second member is false
    // otherwise, I assume std::pair(key, value) is inserted to the binary tree structure wr. to 
    // the ordering of key
    
    //Briefly describe the insert_or_assign() member function of std::map
    // takes in two arguments, first one being the key and second one being the value
    // if there's no element in the map with the same key, then insertion happens
    // -> (I assume) a pair object is initialized and added to the tree
    // if there's an element in the map with the same key, then assignment happens
    // -> pre-existing pair's second member is assigned the new value
    
    
    
	return 0;
}
