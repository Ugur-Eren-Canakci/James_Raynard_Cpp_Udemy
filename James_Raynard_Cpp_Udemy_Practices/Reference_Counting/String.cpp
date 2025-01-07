#include "String.h"
#include <iostream>

int str_size(const char* s) {
    int res = 0;
    auto it = s;
    while (*it != '\0') {
        res++;
        it++;
    }
    return res;
}

// c-style string constructor
String::String(const char* s) : size(str_size(s)), counter(new int{1}) {
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = s[i];
    }        
    data[size] = '\0';
}

// std::string constructor
String::String(const std::string& str) : String::String(str.data()) {}

// default constructor
String::String() : size(0), data(nullptr), counter(nullptr) {}

// show size
int String::show_size() const {
    return size;
}

// show counter
int String::show_counter() const {
    if (counter != nullptr) return *counter;
    return -1;
}

// show string
char* String::show_string() const {
    return data; 
}

// check corrupted object
bool String::check_corrupted() {
    if (size < 0) {
        std::cout << "size less than zero" << std::endl;
        return true;
    }
    if ((data == nullptr && counter != nullptr) || (data != nullptr && counter == nullptr)) {
        std::cout << "data and counter mismatch" << std::endl;
        return true;
    }
    return false;
}

// copy constructor
String::String(const String& other) : size(other.size), data(other.data), counter(other.counter) {
    
    if (counter != nullptr) ++(*counter);
}

// copy assignment operator
String& String::operator=(String& other) {
    if (this != &other) {
        if (counter != nullptr) ++(*(other.counter));
        size = other.size;
        data = other.data;
        counter = other.counter;
    }
    return *this;
}

// move constructor
String::String(String&& other) : size(other.size), counter(other.counter), data(other.data) {
    other.size = 0;
    other.data = nullptr;
    other.counter = nullptr;
}
    
// move assignment operator
String& String::operator=(String&& other) {
    if (this != &other) {
        this->size = other.size;
        this->data = other.data;
        this->counter = other.counter;
        other.size = 0;
        other.data = nullptr;
        other.counter = nullptr;
    }
    return *this;
}

String::~String() {
    if (this->check_corrupted()) {
        std::cout << "corrupt object destructed" << std::endl;
        if (data == nullptr && counter != nullptr) std::cout << "counter isn't deleted, potential memory leak" << std::endl;
        else std::cout << "data isn't deleted, potential memory leak" << std::endl;
    }
    else {
        if (counter != nullptr && data != nullptr) {
            if (*counter > 1) --(*counter);
            else if (*counter == 1) {
                delete [] data;
                delete counter;
            } 
        }
    }
}

