#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <iostream>

class Implementation
{
public:
    Implementation();
    ~Implementation();
    
    void print_address() {
        std::cout << this << std::endl;
    }
};

#endif // IMPLEMENTATION_H
