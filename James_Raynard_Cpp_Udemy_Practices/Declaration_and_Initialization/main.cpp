#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, std::vector<int>& vec) {
    
    for (const auto& el : vec) {
        os << el << " ";
    };
    os << std::endl;
    return os;
}

int main() {
    
    //What is meant by universal initialization in C++?
    int a {5}; // curly brackets are used as a "universal" syntax for the initializations of primitives and objects.
    // brought by c++11
    // if the object holds more than one element, then each element will be initialized by singular values supplied in the curly brackets
    std::vector<int> vec {a, 3};
    for (const auto& el: vec) { //5 3
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    // What are the advantages of universal initialization?
    // makes the code more cohesive
    // some constructors are designed counter-intuitively, and using universal initialization helps with this fact
    
    std::vector<int> vec2(4); // 4 elements, each equal to 0
    std::cout << vec2;
    std::vector<int> vec3(4,2); // 4 elements, each is 2
    std::cout << vec3;
    
    std::vector<int> vec4{4}; // single element vector, element is 4
    std::cout << vec4;
    
    std::vector<int> vec5{4,2}; // elements are 4 and 2
    std::cout << vec5;
    

    //What is meant by a "type alias"? Why is it useful?
    // when types are very long or complicated, we can use type aliases to represent that type with a simpler name
    
    
    // typedef vector<int> IntVec;
    using IntVec = std::vector<int>;
    
    //vector<IntVec> vec_of_vec;
    IntVec vec_of_vec;
    
    
	return 0;
}
