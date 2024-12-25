#include <iostream>

class refrigerator { //The following class does not define any constructors. Why is this problematic?
private:
    int temperature;
    bool door_open;
    bool power_on;
public: 
    refrigerator(int temp, bool door = false, bool power = false)
        : temperature(temp), door_open(door), power_on(power) {}
    
    refrigerator(int temp) : refrigerator(temp, false, false) {}
    
    refrigerator() : refrigerator(23, false, false) {}
    
};
// Answer: The attributes will be initialized with no given values. Hence, they will carry whatever value is already 
// kept in the specific memory block these variables are initiated to. Different objects will have random different 
// values in these attributes, and this doesn't work well.

// What is meant by a "delegating" constructor?
// Answer: referring to one specific constructor for all constructor overloads 
// Why is this useful?
// if there are specific commands in the delegated constructor, those will also be called with the overloads

int main() {
    
	return 0;
}
