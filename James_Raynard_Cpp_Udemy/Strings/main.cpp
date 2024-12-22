#include <iostream>
#include <string>

int main() {
    
    // Strings have two interfaces: the native one, and the STL container
    // Over 100 member functions
    
    std::string s1{"Hello"}, s2 {"World"};
    
    // Assignment 
    s1 = s2; 
    
    // Appending
    s1 += s2;
    
    // Concatenation
    //s1 + s2;
    
    // Comparison
    //s1 < s2;
    //s1 == s2;
    
    // c_str() member fn returns a copy of the string's data as a C-style string
    // array of chars terminated by null character
    // return value is a pointer to a const char
    // useful for passing C++ strings to functions that take C-style strings

    // substr() member fn returns a substring.
    s1 = "Hello World!";
    std::cout << s1.substr(6, 3) << std::endl; // starting from index 6, take 3 elements
    std::cout << s1.substr(6) << std::endl; // starting from index 6, take the rest
    
    std::string s3; // default constructor
    std::string s4 {"Hello"}; // constructor with a string literal 
    std::string s5(3,'x'); // constructor with a count and an initial value
    std::string s6 {'H','i'}; // constructor with an initializer list
    std::string s7(s1,1) ; // constructor with a pre-existing string, from position 1 
    std::string s8(s1, 1, 2); // constructor with a pre-existing string, from index 1 with 2 elements
    
    // find() method 
    // looks for the first occurence of its argument in the string it's called from.
    // The search is case-sensitive
    // arguments can be a char, a std::string or a C-style string
    // If there's no match, it returns string::npos. Otherwise, it returns the index the occurence starts from.

    std::string s9 = "Hello";
    std::cout << s9.find("l") << std::endl;
    std::cout << s9.find("lo") << std::endl;
    
    // We can use the return value from find() as an index, but we must first check if it's valid.
    size_t pos = s9.find("H");
    if (pos != std::string::npos) s9[pos] = 'H';
    else std::cout << "Couldn't find H.\n";
    
    // rfind() method
    // backwards search on the called string
    // second argument for the index to start the search from
    std::cout << s9.rfind('l',2) << std::endl;
    
    // find_first_of(), find_last_of()
    // finds the occurence of any character from the given argument in the string these are called from
    
    // find_first_not_of(), find_last_not_of()
    // finds the occurence of characters in a string that's NOT in the given argument
    
    // append() method
    // usually we use operator+= but append() has this overload:
    std::string s10 = "Hello";
    s10.append(" World!", 1,5);
    std::cout << s10 << std::endl;
    
    // insert() method
    // inserts the second argument to a string right before the index that's in the first argument
    
    std::string s11 = "Hello";
    s11.insert(1, " World!");
    std::cout << s11 << std::endl;
    
    // after the string argument, you can specify where and how long of the second argument you want to place inside the called string
    std::string s12 = "Hello";
    s12.insert(1," World!", 1,3);
    std::cout << s12 << std::endl;
    
    // we can insert a char(not a string!!!) multiple times
    std::string s13 = "Hello";
    s13.insert(1,5, 'r');
    std::cout << s13 << std::endl;
    
    // insert() can also take iterators as arguments
    std::string s14 = "word";
    auto last = s14.end() - 1;
    s14.insert(last,'l');
    std::cout << s14 << std::endl;
    s14.insert(last, 3, 'm');
    std::cout << s14 << std::endl;
    
    //***********IMPORTANT**************
    // Iterator invalidation
    // Inserting elements may fill up the string's memory buffer
    // In this case, it will allocate a new buffer and copy its data into the new buffer before inserting new elements
    // Any iterators initialized before this point will point to the old buffer, and so they become invalid
    // => Reinitialize the iterators you used 
    
    // erase() method
    // takes in two arguments. First arg is the index to start. Second arg is the number of elements to erase.
    std::string s15 = "Hello";
    s15.erase(2,1);
    std::cout << s15 << std::endl;
    
    // erase() has overloads that allow it to run with iterator arguments
    // single iterator arg => element pointed by the iterator is deleted
    // two iterator arg => all elements in the half-open range are deleted
    
    // replace() method
    // first arg is the index of the first character to be replaced
    // second arg is the number of characters to be replaced
    // the remaining arguments give the characters that will replace them
    std::string s16 = "Say Hello";
    s16.replace(4, 5, "Goodbye");
    std::cout << s16 << std::endl;
    
    // Can use iterators with this as usual
    // first arg is the first element to be replaced
    // second arg is the one element after the last to be replaced (half-open range)
    // the rest of the arg is the characters to be placed in
    
    // assign() method
    // will remove all the characters from a string and replace them with other characters
    
    
    
    // Conversion between strings and numbers
    
    // C++11 provided to_string()
    // returns the argument as a std::string object 
    // overloads support all integer and floating-point types
    
    // stoi() - string to integer
    // ignores leading whitespace
    // An optional second argument gives the number of characters which were processed
    size_t n_processed;
    auto i = std::stoi(" 314 159", &n_processed);
    if (n_processed < std::string{" 314 159"}.size()) {
        // partial conversion
        };
    // if the string is not a number, an exception is thrown
    
    // an optional third base is for the base
    std::cout << std::stoi("2a", nullptr, 16) << std::endl;
    // similar fn's exist for long and long longs
    
    // stod() - string to double
    // always in decimal base
    // similar fn's exist for float and long doubles
    
    
    // data() method - std::string and std::vector
    // returns a raw pointer to the containers' internal memory buffer
    // for std::string this is null-terminated string(equivalent to c_str())
    // useful for working with API's written in C
    
    // swap() method
	// non-member version exists, with many many overloads for all the built-in and library types
    // since std::string holds a pointer to the raw string, swap makes the pointers of two strings replace each other
    
    
    // character fn's
    // #include <cctype>
    // isdigit(), islower(), isupper(), isspace(), ispunct()
    // tolower(), toupper()
    
    //*******IMPORTANT********
    // Operations on std::string are case sensitive
    // There's no direct support for case-insensitive comparisons
    // Compiler implementations often provide functions which perform case-insensitive comparisons of C-style strings
    //      These are not standard, not portable and do not directly support std::string
    // Simplest solution is to lowercase strings both before comparison
       
    return 0;
}
