#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

bool match(const std::string& animal, const std::string& value) {
    return animal == value;
}

using namespace std::placeholders;

int main() {
    
    /*• Imagine we want to call count_if() and use the following function as a
    predicate
    

bool match(const string& animal, const string& value) {
    return animal == value;
}


    • Why does this not work?
     * */
    
    //count_if requires a unary predicate to forward the elements inside the container one by one.
    
    //• Suggest two different ways it could be made to work as intended
    // either using std::bind or lambda with an appropriate capture list
    
    //Explain what std::bind() does
    // takes in a callable object and some arguments, and returns a partially called callable object 
    
    // What syntax is used for placeholder arguments?
    // you'd ideally have "using namespace std::placeholders" in the header 
    // _1, _2, ... each one of them is a placeholder for function arguments
    // first argument that's forwarded to the return value of bind will be placed in place of _1
    // second ............................................................................... _2
    // ...
    
    //Rewrite the example from the first slide so that it works correctly, using std::bind()

    auto match_cat = std::bind(match, _1, "cat");
    std::vector<std::string> vec {"cat", "dog", "horse", "hamster", "bird", "cat"};
    auto n = std::count_if(vec.cbegin(), vec.cend(), match_cat);
    std::cout << n << " animals matched cat." << std::endl;
    
    //Rewrite the example from the first slide so that it works correctly, using a lambda with capture and a lambda-local variable
    auto m = std::count_if(vec.cbegin(), vec.cend(), [value = "cat"] (std::string x) {
        return x == value;
    });
    std::cout << m << " animals matched cat." << std::endl;
    
	return 0;
}
