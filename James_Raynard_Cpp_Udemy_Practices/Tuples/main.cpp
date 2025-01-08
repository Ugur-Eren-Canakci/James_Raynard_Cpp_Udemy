#include <iostream>
#include <tuple>

std::tuple<int,int> func() {
    static int i=0;
    i++;
    return {i%3, i%5};
}

int main() {
    
    //What are the main differences between std::pair and std::tuple
    // pair takes two elements, accessible with "first" and "second" data members
    // tuple takes in as many as you want, and elements are accessed with subscript notation
    
    /*Write down code that defines an std::tuple object using
    • Constructor call
    • make_tuple()*/
    
    std::tuple<int,int,int> tuple_1{3,4,5};
    std::tuple<int,int,int> tuple_2 = std::make_tuple(3,4,5);
    
    /*• Write a program that
    • Prints out the first element of your tuple
    • Modifies an element in your tuple
    • Prints out the value of an element with a given type
    */
    std::cout << std::get<0>(tuple_1) << std::endl;
    auto x = std::get<1>(tuple_1);
    std::get<2>(tuple_1) = 6;
    std::cout << std::get<2>(tuple_1) << std::endl;
    
    //What is the purpose of std::tie?
    // Extracts each element in a tuple to a valid variable
    
    //Write a program that uses std::tie with your tuple
    int a,b,c;
    std::tie(a,b,c) = tuple_2;
    std::cout << a << b << c << std::endl;
    
    //Why are tuples useful for returning multiple values from functions?
    // You can use structs to return multiple values, but you need to define the struct in the header for every possible combination of values to be returned
    // tuples can be set with initializer lists and you can return init lists from functions (with type declaration of a tuple in the function definition)
    
    //Write a simple program with a function that returns a tuple
    int x_pos, y_pos;
    for (int i=0; i<5; i++) {
        std::tie(x_pos, y_pos) = func();
        std::cout << "x position: " << x_pos << ", y position: " << y_pos << std::endl;
    }
    return 0;
}
