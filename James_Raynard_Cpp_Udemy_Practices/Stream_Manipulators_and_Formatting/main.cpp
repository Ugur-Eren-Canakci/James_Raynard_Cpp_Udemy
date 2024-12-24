#include <iostream>

int main() {
    
    
    //• Explain what is meant by a "stream manipulator"
    // shapes the way a stream looks on the output streams
    
    //• Write a simple program which prints out Booleans as "true" or "false"
    // insert boolalpha to an outputstream
    
    //What does setw() do?
    // Sets the total amount of space an output holds. 
    // Applies only to the next inserted element
    // setw(n) sets the element to hold n spaces, so right after the previous element, n-length(next_item) spaces are put into the stream, and then the element itself
    
    // What is meant by "justification" in the context of text formatting?
    //How can the justification be changed for a C++ stream?
    // makes the text "aligned" in the given direction
    // inserting "left", "right", or other existing justification keywords into a stream
    // sticky, so will hold for all elements to be inserted. 
    
    //• What effect does applying the setfill manipulator have on the output?
    // replaces whitespace with its argument in the outputstreams
    
    
	return 0;
}
