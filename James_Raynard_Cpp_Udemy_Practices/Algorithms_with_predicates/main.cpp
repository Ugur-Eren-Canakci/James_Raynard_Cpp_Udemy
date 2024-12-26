#include <iostream>
#include <vector>
#include <algorithm>

bool pred_func(const std::string& lhs, const std::string& rhs) {
    return lhs.size() > rhs.size();
}

class pred_functor {
public:
    bool operator() (const std::string& lhs, const std::string& rhs) {
        return lhs.size() < rhs.size();
    }
};


int main() {
    
    //Explain what is meant by a predicate function
    // it's a function that has a boolean return value and its arguments are chosen to be elements of a container
    // they represent the "criteria" on how the elements of a container should be ordered/chosen 
    
    //Why are predicate functions useful with STL algorithms?
    // STL algorithms can use predicate functions instead of their default choice of functions
    // sort() uses operator< as a predicate by default. We can supply sort() with our own "criteria" in the third argument
    
    //Write a program that reads in some words and stores them in a vector. Display the elements of the vector after sorting them by
    // calling std::sort with
    //• The default predicate
    //• A function predicate
    //• A functor predicate
    
    
    int name_count;
    std::cout << "Welcome to the program." << std::endl;
    std::cout << "Please enter how many names you want to enter: " << std::endl;
    std::cin >> name_count;
    std::cout << std::endl;
    
    
    std::vector<std::string> names{};
    for (int i=0; i<name_count; ++i) {
        std::cin.clear();
        std::cout << "Please enter name " << i+1 << ":";
        std::string temp;
        std::cin >> temp;
        names.push_back(temp);
    }
    std::cin.clear();
    
    std::cout << "Sorting by alphabetic order: ";
    std::sort(names.begin(), names.end());
    for (const auto& el : names) {
        std::cout << el << ",";
    }
    std::cout << std::endl;
	
    std::cout << "Sorting from longest to shortest: ";
    std::sort(names.begin(), names.end(), pred_func);
    for (const auto& el : names) {
        std::cout << el << ",";
    }
    std::cout << std::endl;
    
    pred_functor p;
    std::cout << "Sorting from shortest to longest: ";
    std::sort(names.begin(), names.end(), p);
    for (const auto& el : names) {
        std::cout << el << ",";
    }
    std::cout << std::endl;
    return 0;
}
