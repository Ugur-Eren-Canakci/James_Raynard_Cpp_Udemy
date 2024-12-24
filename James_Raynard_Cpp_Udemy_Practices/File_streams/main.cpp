#include <iostream>

int main() {
    
    //Explain the similarities and differences between iostream and fstream
    // >> and << defined for both
    // iostream is strictly for console input and outputs
    // both can be used for similar purposes like keeping data, interacting with users, etc
    
    //Describe how to open a file for reading (i.e., receiving input from the file)
    // you initialize the right kind of stream for the file, with using the right arguments such as the file location and stream mode
    
    //How can we tell whether the file was successfully opened?
    // .is_open() returns true
    // !in_file returns false
    // .good(), .fail(), .bad() methods for (some?) fstreams
    
    //What happens when fstream's destructor is called?
    // file is closed, i.e. .close() is called on the fstream object
    // buffers are flushed to the data
    // memory released
    
    

    
	return 0;
}
