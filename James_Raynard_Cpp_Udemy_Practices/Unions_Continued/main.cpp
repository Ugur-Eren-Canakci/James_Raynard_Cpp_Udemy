#include <iostream>

enum class Tag {Integer, Double};

union Token {
public:
    int i;
    double d;
};

class WrapperToken {
private:
    Token token;
    Tag tag;
public:
    void set_int(int i) {
        tag = Tag::Integer;
        token.i = i;
    }
    
    int get_int() {
        if (tag == Tag::Integer) {
            return token.i;
        }
        else {
            throw std::invalid_argument("Token is currently not an integer.");
        }
    }
};

int main() {
    
    //• What is the advantage of wrapping a tagged union inside a class?
    // eliminates user mistakes by having a tagged union as a private member and managing access via the public members of the class
    
    //• Write a simple class which wraps a tagged union
    //• Only implement one "getter" and one "setter" member function
    //Write a simple program to test your class, similar to the previous exercises
    
    WrapperToken obj;
    try {
        obj.get_int();
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    obj.set_int(3);
    obj.get_int();
	return 0;
}
