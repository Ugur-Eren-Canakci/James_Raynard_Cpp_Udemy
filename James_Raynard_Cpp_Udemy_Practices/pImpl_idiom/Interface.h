#ifndef INTERFACE_H
#define INTERFACE_H
#include "Implementation.h"
#include <memory>

class Implementation;

class Interface {
private:
    std::unique_ptr<Implementation> pImpl;
public:
    Interface();
    ~Interface();
    
    void print_address() {
        pImpl->print_address();
    }
};

#endif // INTERFACE_H
