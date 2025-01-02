#include <iostream>

int main() {
    
    //What is meant by a "pure virtual member function"?
    /*• Why are pure virtual functions useful?
    • What effect does making a member function pure virtual have?
    What is an "abstract base class"?
    • An abstract base class contains a pure virtual member function
    • What is an abstract base class used for?
    * 
     * */
    // these are virtual functions defined in the base class with " = 0 " suffix and no function body
    // these functions make their class abstract
    // you cannot initialize an abstract class
    // derived classes have to manually define the override version of this function
    // if they don't override the pure virtual functions, they inherit it
    // since pure virtual functions turn the class they're in into abstract classes,
    // now the derived class is also not constructible
    // abstract classes define the common themes in the future derived classes
    // they also "list" the mandatory functionality of the derived classes
    
    //• What is meant by "object slicing?"
    // If a function takes a base class on a pass-by-value argument, any passed derived class will "lose their derived parts"
    // inside the function stack.
    // pass-by-value copies the passed argument into the function stack
    // since the function takes in a base object, base class copy constructor is called
    // => base part of the derived object is copied, but not the rest
    
    
    
	return 0;
}
