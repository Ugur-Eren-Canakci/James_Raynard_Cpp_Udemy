#include <iostream>

int main() {
    
    // number is too long to fit in the usual 6-digit precision of doubles. hence, scientific notation is used by cout
    double c {299'792'458};
    std::cout << c << std::endl;

    double d {299'792'458};
    std::cout << std::fixed << d << std::endl;
    double e {1.602e-19};
    std::cout << std::fixed << e << std::endl;

	return 0;
}
