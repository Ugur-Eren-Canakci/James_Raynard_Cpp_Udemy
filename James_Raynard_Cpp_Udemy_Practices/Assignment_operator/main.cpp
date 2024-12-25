#include <iostream>

int main() {
    
    //• Explain what an assignment operator is
    // .operator=(const object_type& other)
    // takes in a const reference to assign the reference's values into the called object
    
    //How is it invoked?
    // y = z; (equal to y.operator=(z);)
    
    //Why is *this not returned as a const reference?
    // STL containers won't accept const reference.
    // There are cases where the returned value has to be non-const
    
    
    
    
    std::cout << "Default Project Template" << std::endl;
	return 0;
}
