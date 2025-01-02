#include <iostream>
#include <vector>

class Shape {
public:
    virtual void print() {
        std::cout << "This is a shape." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    virtual void print() {
        std::cout << "This is a rectangle." << std::endl;
    }
};

class Triangle : public Shape {
public:
    virtual void print() {
        std::cout << "This is a triangle." << std::endl;
    }
};

class Circle : public Shape {
public:
    virtual void print() {
        std::cout << "This is a circle." << std::endl;
    }
};


int main() {
    
    //Explain the difference between the static type of a variable and its dynamic type
	// static type is the type definition in the variable declaration
    // dynamic type is the type of the value held in the memory of this variable
    
    //Write a simple program that uses the dynamic type of an object
    Triangle t;
    Rectangle r;
    Circle c;
    
    Shape* t_ptr(&t);
    Shape* r_ptr(&r);
    Shape* c_ptr(&c);
    
    std::vector<Shape*> ptr_vec;
    
    ptr_vec.push_back(t_ptr);
    ptr_vec.push_back(r_ptr);
    ptr_vec.push_back(c_ptr);
    
    for (const auto& el : ptr_vec) {
        el->print();
    }
    return 0;
}
