#include <iostream>
#include <vector>

int main() {
    
    //Write a program which creates an empty vector of int and populates it with the values 4, 2, 3, 4, 1 in order
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(1);
    
    for (const auto& el:vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    //Display the first and the fourth elements of the vector
    std::cout << vec.at(0) << " " << vec.at(3) << std::endl;
    
    // Change the value of the third element to 6
    vec[2] = 6;
    for (const auto& el:vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    // Write a program which creates a string containing the characters "Hello"
    std::string s{"Hello"};
    //Display the first and fifth characters of the string
    std::cout << s[0] << " " << s[4] << std::endl;
    //Change the value of the fourth character to 'b'
    s[3] = 'b';
    std::cout << s << std::endl;
    
	return 0;
}
