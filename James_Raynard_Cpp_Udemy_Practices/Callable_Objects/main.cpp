#include <iostream>
#include <functional>
#include <vector>

bool match(const std::string& test) {
    return test == "cat";
}

int count_strings_1(std::vector<std::string>& vec) {
    int counter = 0;
    for (const auto& el : vec) {
        if (match(el)) counter++;
    }
    return counter;
}


int count_strings_2(std::vector<std::string>& vec, std::function<bool(const std::string&)> func) {
    int counter = 0;
    for (const auto& el : vec) {
        if (func(el)) counter++;
    }
    return counter;
}

int main() {
    
    //What is the purpose of std::function?
    // it's a class that contains a private member, storing a callable object of type that's given in the template parameter 

    /*Write a count_strings function similar to std::count_if which
    • Takes a vector of std::string and a function pointer
    • Calls the function on each element
    • If the function returns true, increments a counter
    • Returns the final value of the counter
    */
    auto match_ptr = match;
    std::vector<std::string> vec {"cat", "dog", "horse", "cat", "hamster"};
    int m = count_strings_1(vec);
    std::cout << m << " strings have matched." << std::endl;
    /*• Write a program to test your code. It should work correctly with this function
    bool match(const string& test) {
    return test == "cat";
    }
    */
    int n = count_strings_2(vec, match_ptr);
    std::cout << n << " strings have matched." << std::endl;
    

	return 0;
}
