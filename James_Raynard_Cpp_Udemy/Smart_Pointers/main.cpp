#include <iostream>
#include <memory>
#include <vector>


class Base {
public:
    virtual void print() {
        std::cout << "Base" << std::endl; 
    }
};
class Derived : public Base {
public:
    virtual void print() override {
        std::cout << "Derived" << std::endl;
    }
};


std::unique_ptr<Base> factory_fn(int choice) {
    if (choice == 0) return std::make_unique<Base>();
    else if (choice == 1) return std::make_unique<Derived>();
    else {
        std::cout << "Invalid argument. Returning a nullptr." << std::endl;
        return std::unique_ptr<Base>{nullptr};
    }
}

int main() {
    
    // polymorphism with unique pointers
    std::unique_ptr<Base> base_ptr_1 {new Derived};
    std::unique_ptr<Base> base_ptr_2 {std::make_unique<Derived>()};
    std::unique_ptr<Base> base_ptr_3 {std::make_unique<Base>()};
    
    
    std::vector< std::unique_ptr<Base> > base_ptr_vec;
    base_ptr_vec.push_back(std::move(base_ptr_1));
    base_ptr_vec.push_back(std::move(base_ptr_2));
    base_ptr_vec.push_back(std::move(base_ptr_3));
    for (auto& el : base_ptr_vec) {
        el->print();
    }
    
    // factory pattern
    auto el_1 = factory_fn(0);
    el_1->print();
    auto el_2 = factory_fn(1);
    el_2->print();
    auto el_3 = factory_fn(2);
    el_3->print(); // crashes the program as you can't dereference a nullptr

    
    
	return 0;
}
