#include <iostream>

class Vehicle {
private:
    double max_speed;
public:
    Vehicle(double max_speed) : max_speed(max_speed) {
        std::cout << "Vehicle constructor" << std::endl;
    }
};

class Aeroplane : public Vehicle {
private:
    double max_height;
public:
    Aeroplane(double max_speed, double max_height) : Vehicle(max_speed), max_height(max_height) {
        std::cout << "Aeroplane constructor" << std::endl;
    }
};


class FighterPlane : public Aeroplane {
public:
    FighterPlane(double max_speed, double max_height) : Aeroplane(max_speed, max_height) {
        std::cout << "Fighter Plane constructor" << std::endl;
    }
};


int main() {
    
    /*
     * A Vehicle class has a max_speed member
    • An Aeroplane class has a max_height member
    • Aeroplane is derived from Vehicle
    • Write the class definitions for a Vehicle class and an Aeroplane class
    • Check that your code compiles
     * */
    /*
     * Add constructors to your class definitions
    • In the constructor body, print out the type of the class
    • Write a main function which creates an object of each class
    • What happens when you run your code?
    • Explain the results
     * 
     * */
    Vehicle car(150); 
    Aeroplane flight_jet(700, 45000);
    // Since Aeroplane class is derived from Vehicle class, 
    // When initializing an Aeroplane object we initialize a Vehicle object
    // Next to the memory blocks of this initialized Vehicle object, C++ adds the data members of the Aeroplane class
    
    //• Write a new version of the class hierarchy in which a FighterPlane is derived from Aeroplane
    FighterPlane fighter_jet(850,50000);
    
	return 0;
}
