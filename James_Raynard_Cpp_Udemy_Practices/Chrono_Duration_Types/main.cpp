#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std::literals;

int main() {
    
    //What is meant by a duration unit in the std::chrono library?
    // these are types defined in <chrono> and are in namespace std::chrono
    // ..., hours, mins, seconds, ...
    // we can set variables to have these types, but we have to be careful while assigning values
    // brackets can take integer values, but operator= and operator() require literal types as arguments
    
    /*Write down expressions that define duration objects which represent
intervals of
• 2 seconds
• 20 milliseconds
• 50 microseconds*/
    
    seconds sec{2}; // 2 seconds
    milliseconds mlsec{20}; // 20 milliseconds
    microseconds mcsec{50}; // 50 microseconds
    
    //• Repeat the previous exercise, using standard literals
    seconds sec_2 = 2s;
    milliseconds mlsec_2 = 20ms;
    microseconds mcsec_2 = 50us;
    
    /*Write a simple program which creates some duration objects and
prints out their values*/
    std::cout << sec.count() << " " << mlsec.count() << " " << mcsec.count() << std::endl;
	std::cout << sec_2.count() << " " << mlsec_2.count() << " " << mcsec_2.count() << std::endl;
    
    //What happens if the object is not explicitly initialized?
    // if no value is given in the initialization, the assigned memory address will contain a garbage value
    
    //Write a simple program which performs some operations on duration types and prints out the results
    std::cout << (2s + 50min).count() << std::endl;
    
    //What conversions are supported by duration types?
    // int to chronotype if initialization is done with curly brackets
    // otherwise, explicit conversion is necessary
    // if not using duration_cast, conversion is allowed only if no information is lost
    // in the sense of losing significant figures 
    
    
    return 0;
}
