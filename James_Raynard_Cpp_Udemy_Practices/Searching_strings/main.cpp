#include <iostream>
#include <string>
#include <vector>

int main() {
    
    
    //Write a program which creates a string with the characters "Hello
    //world"
    //• Find the following characters or substrings in the string and display
    //suitable output. Make sure you handle the case where the search is
    //unsuccessful
    //• 'o'
    //• "or"
    //• 'O'
    
    // .find() returns the first position the argument appears, and returns std::npos if the argument is not found.
    std::string s{"Hello world"};
    std::vector<std::string> vec {"o", "or", "O"};
    
    for (const auto& el : vec) {
        if (s.find(el) != std::string::npos) {
            std::cout << el << " found at " << s.find(el) << std::endl;
        }
        else {
            std::cout << el << " not found" << std::endl;
        }
    };


    //Explain what the std::string member function rfind() does
    //• Repeat the previous exercise but using rfind() instead of find(). What
    //result do you expect?
    for (const auto& el : vec) {
        if (s.rfind(el) != std::string::npos) {
            std::cout << el << " found at " << s.find(el) << " with reverse search." << std::endl;
        }
        else {
            std::cout << el << " not found with reverse search." << std::endl;
        }
    };
    
    std::string str3("cash");
    str3.insert(1, 3, 'r');
    std::cout << str3 << std::endl;
    
    
    //What is meant by "iterator invalidation" in the context of calling insert() on std::string?
    // new element(s) is added to the string. hence, iterators that used to "point to the old state" are now invalid as newly added element(s) would be passed over with those old iterators
    

    return 0;
}
