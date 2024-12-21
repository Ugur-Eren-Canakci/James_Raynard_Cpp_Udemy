#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <map>

int main() {
    
    std::vector<int> vec {1,2,3,4,5,6};
    std::cout << vec.size() << "\n";
    auto mid = vec.begin() + vec.size()/2;
    std::cout << *mid;
    
	return 0;
}
