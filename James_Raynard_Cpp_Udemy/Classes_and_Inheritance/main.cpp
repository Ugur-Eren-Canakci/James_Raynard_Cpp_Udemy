#include <iostream>
#include <vector>

class Base {
public:
    void fn() {
        std::cout << "Base fn called" << std::endl;
    }
};

class Derived : public Base {
public:
    void fn() {
        std::cout << "Derived fn called" << std::endl;
    }
};


int main() {
    
    // Base ptr example
    std::vector<Base*> vec;
    vec.push_back(new Derived);
    
    for (const auto& el : vec) {
        el->fn();
    }
    // only one Base ptr is in vec
    // Since it's a Base ptr, compiler will call Base::fn()
    
    // If you seriously need to call Derived::fn(), static_cast the pointer to a Derived pointer
    for (const auto& el : vec) {
        static_cast<Derived*>(el)->fn();
    }
    // Obviously, if you have different derived classes in vec, this would cause false calls
    
    for (const auto& el : vec) {
        delete el;
    }
    
	return 0;
}

