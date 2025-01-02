#include <iostream>

class Base {
protected:
    int x;
public:
    Base(int x) : x(x) {}
    virtual void print() const {
        std::cout << "Base" << std::endl;
    }
};

class Child : public Base {
public:
    Child(int x) : Base(x) {} 
    virtual void print() const override {
        std::cout << "Child" << std::endl;
    }
};

class Grandchild : public Child {
public:
    Grandchild(int x) : Child(x) {}
    virtual void print() const override {
        std::cout << "Grandchild" << std::endl;
    }
};

void print_class(Base& obj) {
    obj.print();
}

int main() {
    
    /*Write an inheritance hierarchy with three classes: Base, Child and Grandchild. 
     * Do not define any constructors or data members for these classes.
    Child inherits from Base and Grandchild inherits from Child.
    Give each class a print() member function which prints out the name of the class
    Write a print_class() function which takes a Base argument by value
    Create an object of each class and pass it to a call to print_class()
 * */
    
    Base b(0);
    Child c(0);
    Grandchild g(0);
    
    print_class(b);
    print_class(c);
    print_class(g);
    
    // when print_class takes arg by value, it creates a copy of a Base object. Hence, the passed object is Base, and so
    // the function binding is static
    // when print_class takes arg by reference, since print() is virtual, the print() function is binded dynamically onto the print call.
    
	return 0;
}
