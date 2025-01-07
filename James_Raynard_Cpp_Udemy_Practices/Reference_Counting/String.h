#ifndef STRING_H
#define STRING_H

#include <iostream>

int str_size(const char* s);

class String {
private:
    int size;
    char* data;
    int* counter;
public:
    // c-style string
    String(const char* s);
    
    // std::string constructor
    String(const std::string& str);
    
    // default constructor
    String();
    
    // change size (only if String doesn't contain a string)
    bool change_size(int n);
    
    // copy constructor
    String(const String& other);
    
    // copy-assignment operator
    String& operator=(String& other);
    
    // move constructor
    String(String&& other);
    
    // move assignment operator
    String& operator=(String&& other);
    
    // destructor
    ~String();
    
    // show size
    int show_size() const ;
    
    // show counter
    int show_counter() const;
    
    // show data
    char* show_string() const;
    
    // check if object is corrupted
    bool check_corrupted();
};

#endif // STRING_H
