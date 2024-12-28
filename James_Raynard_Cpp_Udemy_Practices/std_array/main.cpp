#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>


void print_array(const std::array<int, 3>& arr) {
    std::cout << "\nstd::array" << std::endl;
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void print_array(const int arr[]) {
    std::cout << "classic array" << std::endl;
    for (int i=0; i<3; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    
    // What are the main advantages of std::array over built-in arrays?
    // size is known at construction
    // no decaying to pointer
    // implements raw arrays already, which is obtained from .data() member fn
    
    //In what situations would it be preferable to use a built-in array instead of either an std::array or std::vector?
    // If the program has to be C-compatible
    
    //Write a program which
    //• Creates and initializes an std::array
    //• Prints out an element of the array
    //• Modifies an element of the array and prints out the result
    std::array<int, 3> arr {1,2,3};
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    arr[0] = 4;
    
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    //What forms of loops are available with std::array?
    // range-loops as seen above are available
    // iterators are also usable, hence STL algorithms can be run on arrays 
    
    // • Modify your program from the last exercise to print out the elements of the std::array. Use all the forms of loop which are supported
    std::for_each(arr.begin(), arr.end(), [] (int x) { std::cout << x << " "; });
    std::cout << std::endl;
    
    auto it = arr.begin();
    do {
        std::cout << *it << " ";
        it++;
    } while (it != arr.end());
    std::cout << std::endl;
    
    it = arr.begin();
    while (it != arr.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    
    // Modify your program to assign one std::array object to another. Print out the elements of the assigned-to array
    
    std::array<int, 3> arr2;
    std::copy(arr.begin(), arr.end(), arr2.begin());
    for (const auto& el : arr2) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    
    // Why the interface of std::array not exactly the same as for std::vector?
    // there's no push_back for std::array since its size is fixed
	
    //Write a function which takes an std::array and prints out its elements
    print_array(arr);
    print_array(arr.data());
    
    //What happens if you pass an std::array with the wrong number of elements? Explain your results
    std::array<int, 4> arr3;
    std::iota(arr3.begin(), arr3.end(), 1);
    print_array(arr3);
    print_array(arr3.data());
    // the overload that takes std::array caused an error
    // the other overload didn't.
    
    return 0;
}
