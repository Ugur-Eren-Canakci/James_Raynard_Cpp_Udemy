#include <iostream>
#include <bitset>

int main() {
    
    /*Write a program which creates a bitset object and prints out its value
    • As a binary number
    • As a decimal number
    • As an std::string
     * */
    
    std::bitset<8> b1{0b10100101};
    std::cout << "b1: " << b1 << std::endl;
    
    std::bitset<8> b2{"10100101"};
    std::cout << "b2: " << b2 << std::endl;
    
    std::bitset<8> b3{255};
    std::cout << "b3: " << b3 << std::endl;
    
    //• Iterate over all the bits in the object and print out their values
    // recall: subscript indexing works in inverse order for bitsets
    std::cout << "b1: ";
    for (int i=7; i>-1; i--) {
        std::cout << b1[i];
    }
    std::cout << std::endl;
    
    // Attempt to access a bit which is outside the object's range
    try {
        std::cout << b1.test(8) << std::endl;
    }
    catch (std::out_of_range& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    
    
	return 0;
}
