#include <iostream>
#include <tuple>

std::tuple<double, int, std::string> func() {
    return {1.0, 2, "three"};
}

void func_2(int x) {
    std::cout << x << ", ";
}


class Base {
private:
    int x, y, z;
public:
    Base(int x, int y, int z) : x(x), y(y), z(z) {
        std::cout << "Base constructor called" << std::endl;
    }
};


int main() {
    
    //Write down code that defines an std::tuple object, without using make_tuple() or explicit type parameters
    std::tuple tuple_1{1.0, 2, "three"};
    
    //Write a simple program with a function that returns an std::tuple
    //Use a structured binding to unpack the elements of the returned tuple
    auto [d,i,s] = func();
    
    //• Write a simple program which calls std::apply() and passes an std::tuple object to it
    // std::apply( func_2, std::tuple<int,int,int>(1,2,3) ); doesn't work for some reason
    
    /*• Write a simple program that uses an std::tuple to initialize an object
    of a class, without calling std::get()
    */
    std::tuple tuple_2 {1,2,3};
    auto test = std::make_from_tuple<Base>(tuple_2);
	return 0;
}
