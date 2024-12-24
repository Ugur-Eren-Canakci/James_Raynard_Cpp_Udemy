#include <iostream>

int main() {
    
    
    //• Write down expressions which perform the following operations on
    //std::variables s1 and s2
    //• Briefly describe the result of each operation
    //• Assignment
    //• Appending
    //• Concatenation
    //• Comparison
    
    // assignment is done by operator=, and the value on the right is put into the variable on the left
    // s1 = s2 takes s2's value and places it in s1
    // if you append s2 onto s1, s1 will turn into "s1's_values2's_value", with no gaps in between the values 
    // concat == append
    // comparison is done by comparing every char in two strings. 
    // if sizes are not equal then it returns false
	// if there's one or more non-matching characters, it again returns false
    // otherwise, returns true
    
    //Describe how to obtain a C-style string from a std::string variable
    //When might this be useful?
    
    // std::string holds a private raw pointer pointing to a c-style string (in the heap?). you can use .data() method on an std::string object to obtain the c-style string the aforementioned pointer points to
    std::string s {"Hello world!"};
    std::cout << s.data() << std::endl;
    // useful when interacting with C environments, hardware applications, etc.
    
    //Convert the code into a working program. At the end of the program,
    //print out the strings
    //string str {"Hello world"};
    //str[1] = 'a';
    //string s1 = str.substr(6);
    //string s2 = str.substr(6,2);
    //• What results do you expect?
    
    std::string str {"Hello world"};
    str[1] = 'a'; // "Hallo world"
    std::string s1 = str.substr(6); //"world"
    std::string s2 = str.substr(6,2); //"wo"
    std::cout << s2 << std::endl;
    
    //• Explain what the code below does
    //• Convert it into a working program which prints out each string's data
    //and the number of elements it has
    //• What results do you expect?
    //string hi { "Hello" };
    //string howdy { 'H', 'e', 'l', 'l', 'o' };
    //string triplex(3, 'x');
    //string hello(hi, 1);
    //string hello2(hi, 1, 3);
    
    std::string hi {"Hello"};
    std::string howdy { 'H', 'e', 'l', 'l', 'o' };
    std::string triplex(3, 'x'); //"xxx"
    std::string hello(hi, 1);//"ello"
    std::string hello2(hi, 1, 3);//"el" WRONG! actually "ell
    std::cout << hi << howdy << triplex << hello << hello2;
    
    return 0;
}
