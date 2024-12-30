#include <iostream>
#include <forward_list>
int main() {
    
    //• Describe the structure of a linked list
    // Made of nodes
    // Each node holds a data member and a pointer to the next node
    // First node has no pointer pointing to it,
    // and the last node has a nullptr for its pointer member
    
    // How does this differ from the other containers we have used so far?
	// Only forward iteration is allowed
    // Also insertion and erasing is done in forward direction

    //Describe how to iterate through the elements of a linked list
    // You can hold a pointer variable to point to the beginning of the list
    // After each iteration, we can access the node pointed by this pointer
    // The node's pointer member then can be assigned onto the iteration pointer we had at the beginning
    // We can keep doing this until a node's pointer is nullptr
    
    //• Describe how to add an element to a linked list
    // If you're adding an element to the end of the list, then the previous element's pointer will be assigned this new node's address
    
    // If you're adding to the middle of the list, then the previous element's pointer member is assigned to the new node's pointer member
    // After that, the previous node's pointer is assigned the address of the new node
    
    // If you're adding to the start, then the new node's pointer member will be assigned the list's first element's address
    
    
    //Describe how to remove an element from a linked list
    // If you're removing a node from the end, the previous node's pointer member will be assigned nullptr
    // If you're removing a node from the middle, then the previous node's pointer member will be assigned the next node's address and the removed node 
    // will be destroyed
    // If you're removing the first node, you just destroy it.
    
    //• Write a program which
    //• Creates an std::forward_list object
    //• Inserts an element in the middle of the list
    //• Removes the newly-added element
    //• After each operation, print out all the elements of the list
    
    std::forward_list list {1,2,3,4,5};
    auto it = list.begin();
    ++it;
    ++it;
    
    list.insert_after(it, 6);
    std::cout << "list after inserting 6 in the middle: ";
    for (const auto& el : list) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    list.erase_after(it);
    std::cout << "list after removing the middle element: ";
    for (const auto& el : list) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    
    return 0;
}
