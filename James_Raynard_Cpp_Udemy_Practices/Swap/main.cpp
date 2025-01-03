#include <iostream>

class Object {
public:
    int x, y;
    Object(int x, int y) : x(x), y(y) { std::cout << "two-args constructor" << std::endl; }
    friend void swap(Object& o1, Object& o2) {
        int temp_x = o2.x;
        int temp_y = o2.y;
        o2.x = o1.x;
        o2.y = o1.y;
        o1.x = temp_x;
        o1.y = temp_y;
    }
};

int main() {
    
    //Is it worthwhile overloading swap() for our own classes?
    // If the objects take long time to copy, yes
    
    //• What happens if we do not overload swap()?
    // the generic std::swap is used, which copies the objects in the arguments
    
    //What issues should we consider when overloading swap() for our class?
    // Heap allocations, database/cloud connections
    // basically any resource allocation
    
    /*• Write a simple class
    • Implement an overload of swap() for your class
    • Write a program to test your code
 * */
    Object o1(3,5);
    Object o2(6,8);
    std::cout << "o1: (" << o1.x << "," << o1.y << ")" << std::endl; 
    std::cout << "o2: (" << o2.x << "," << o2.y << ")" << std::endl;
    swap(o1,o2);
    std::cout << "o1: (" << o1.x << "," << o1.y << ")" << std::endl; 
    std::cout << "o2: (" << o2.x << "," << o2.y << ")" << std::endl;
    return 0;
}
