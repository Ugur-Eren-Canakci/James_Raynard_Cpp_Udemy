#include <iostream>
#include <chrono>

using namespace std::chrono;

int main() {
    
    minutes a{3};
    seconds b{287};
    std::cout << (a+b).count() << std::endl;
	return 0;
}
