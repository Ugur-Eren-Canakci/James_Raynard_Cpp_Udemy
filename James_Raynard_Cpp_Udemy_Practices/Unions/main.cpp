#include <iostream>

enum class Tag {Integer, Char};

union Token {
    int i;
    char c;
    Tag tag;
};

int main() {
    
    //Briefly describe the C++ union
    // a data structure with no special member functions
    // the members are kept in the same memory address, and only one member is well-defined at a time
    // you can only have one member of each possible type
    // each member is public by default
    
    //Write a simple program which creates a union and assigns one of its members
    Token token;
    token.i = 3;
    std::cout << token.i << std::endl;
    token.c = '5';
    std::cout << token.c << std::endl;
    
    //What happens if the program accesses a different member?
    // very likely to have a garbage value in the not-used members
    
    //• What is a "tagged" union?
    // a better version of union, keeping what member is defined at a time in a new member called "tag"
    
    //Why are tagged unions useful?
    // reduces the likelihood of reading the wrong member
    // Are there any drawbacks to tagged unions?
    // the tag member may not be updated, creating confusion
    
    //Write a simple program which creates a tagged union and assigns one of its members
    token.tag = Tag::Integer;
    token.i = 6;
    
    //What happens if the program accesses a different member?
    // garbage value returned
    
    
	return 0;
}
