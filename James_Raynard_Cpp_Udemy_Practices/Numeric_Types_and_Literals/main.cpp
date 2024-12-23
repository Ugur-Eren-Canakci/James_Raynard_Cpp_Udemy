#include <iostream>
#include <cstdint>

int main() {
    
    //List the four main integer types in C++11
    // int, short, long, long long
    
    //Write a program which displays the number of bytes each type occupies in memory
    std::cout << "size of int: " << sizeof(int) << std::endl;
    std::cout << "size of short: " << sizeof(short) << std::endl;
    std::cout << "size of long: " << sizeof(long) << std::endl;
    std::cout << "size of long long: " << sizeof(long long) << std::endl;
    
    
    //Write a program which displays the number of bytes each fixed-width integer type occupies in memory
    std::cout << "size of uint8_t: " << sizeof(uint8_t) << std::endl;
    std::cout << "size of uint16_t: " << sizeof(uint16_t) << std::endl;
    std::cout << "size of uint32_t: " << sizeof(uint32_t) << std::endl;
    std::cout << "size of uint64_t: " << sizeof(uint64_t) << std::endl;


    /*Write a program that creates literals in the following bases and prints
    them out
    • Decimal
    • Hexadecimal
    • Octal
    • Binary
    */
    
    int decimal {10};
    int hexadecimal {0x10};
    int octal {010};
    int binary {0b10};
    
    std::cout << decimal << std::endl;
    std::cout << hexadecimal << std::endl;
    std::cout << octal << std::endl;
    std::cout << binary << std::endl;
    
    //Write a program that uses numeric literals with a digit separator and prints them out
    std::cout << double{3.14'159};

	return 0;
    
 


}
