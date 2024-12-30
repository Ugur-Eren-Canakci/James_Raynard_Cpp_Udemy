#include <iostream>
#include <list>

void print_list(const std::list<int>& list) {
    for (const auto& el : list) std::cout << el << " ";
    std::cout << std::endl;
}

int main() {
    
    //Which list types does the C++ standard library provide?
    // Forward_list and list
    // first one is single-linked, the second is double-linked
    
    //• Explain what happens when a new element is added at the end of an std::list
    // New node's previous pointer is assigned the last element's address
    // New node's after pointer is assigned nullptr
    // Previous node's after pointer is assigned the new node's address

    //• Explain what happens when a new element is added in the middle of an std::list
    // New node's previous pointer is assigned the previous node's address  
    // New node's after pointer is assigned the after node's address 
    // Previous node's after pointer is assigned the new node's address
    // After node's previous pointer is assigned the new node's address
    
    //Explain what happens when an existing element is removed from an std::list
    // Previous node's after pointer is assigned the next node's address
    // The next node's previous pointer is assigned the previous node's address
    
    // Write a simple program which creates list instance, initializes it, and
    // adds and removes some elements. After each operation, display the
    // list elements
    
    std::list<int> list{1,2,3,4,5};
    auto it = list.cbegin();
    it++;
    it++;
    // it points to the middle element
    std::cout << *it << std::endl;
    
    list.insert(it, 6);
    print_list(list); // 1 2 6 3 4 5
    // insert() inserts a given element right before the element the iterator points to
    
    list.erase(it);
    print_list(list); // 1 2 6 4 5
    // if you want to delete 6 again, the iterator should decrement by one and then be forwarded to erase
    
    //• Give some advantages and disadvantages of using lists compared to vector
    // Adding/removing elements is very quick
    // Accessing elements takes longer than vectors
    // No operator[] or .at() defined for lists
    
    
	return 0;
}
