#include <iostream>
#include <string>


int main() {
    
    //Write a program that uses iterators to print the second, the last and the middle elements of an std::string object
    std::string s {"abcdefg"};
    auto start = s.begin();
    auto end = --(s.end());
    auto mid = s.begin() + (s.end() - s.begin())/2;
    std::cout << *start << *end << *mid;
    
	return 0;
}
