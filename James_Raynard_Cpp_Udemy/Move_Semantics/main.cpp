#include <iostream>

int main() {
    
    const int& x = 3;
    //x++; error: increment of read-only reference 'x'
    //int& y = 3; error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    
	return 0;
}
