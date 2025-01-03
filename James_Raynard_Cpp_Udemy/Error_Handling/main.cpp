#include <iostream>
#include <vector>


int main() {
    
    int x=0;
    std::vector<int> vec;
    
    if (true) {
        x += 1;
    }
    std::cout << x << std::endl;
    try {
        std::cout << vec.at(1) << std::endl;
        x += 1; // discarded
        std::cout << x << std::endl; // discarded
    }
    catch (const std::exception& e) {
        std::cout << "Error message: " << e.what() << std::endl;
    }
    
	return 0;
}
