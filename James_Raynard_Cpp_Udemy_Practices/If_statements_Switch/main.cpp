#include <iostream>

enum Temp {GOOD, BAD, UGLY};

int main() {
    
    // What does it mean to have an initializer in an if statement?
    // localizes the index variable to the if statement
    // alleviates the requirement of initializing said index variable before if statement
    
    //Write a simple program that uses an initializer in an if statement
    
    if (int i=0; i<1) {
        i++;
    }
    
    //What does it mean to have an initializer in a switch statement?
    // same with if statements
    // can do controls on the newly initialized value
    
    Temp temp {GOOD};
    
    switch (Temp temp_2 = temp) {
        case GOOD:
            [[fallthrough]]
        case BAD:
            [[fallthrough]]
        case UGLY:
            [[fallthrough]]
        default : 
            std::cout << "abcdef";
    }
    
    //Why is the fallthrough attribute useful?
    // it's like a convention thing. not necessary to put it there, i believe, it makes it easier to read
    // if various cases are going to have the same commands executed, then [[fallthrough]] makes those cases do nothing, except the last one, 
    // which will execute those commands
	
    
    return 0;
}
