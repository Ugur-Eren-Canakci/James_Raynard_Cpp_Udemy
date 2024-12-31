#include <iostream>
#include <string>
#include <map>

class Book {
private:
    std::string title;
    std::string publisher;
public: 
    Book(std::string t, std::string p) : title{t}, publisher{p} {} // default two-arg constructor
};

class Book_index { // compound key 
private:
    std::string author;
    std::string title;
public:
    Book_index(std::string a, std::string t) : author{a}, title{t} {} // default two-arg constructpr
    bool operator<(const Book_index& other) {
        if (this->author == other.author) {
            return this->title < other.title;
        }
        
        return this->author < other.author;
    }
}
int main() {
    
    
    // Sequential containers
    // std::string and std::vector
    
    // data is stored in an order which is determined by the program
    // the order doesn't depend on the value of the data
    // the data will remain in the same position unless the program performs some action which changes them
    
    // useful for storing data in an order which we can choose
    // usually, we can access data by its position
    
    // Associative containers
    // sets and maps
    
    // the order depends on the data
    // each element has a "key" which identifies it
    // the key is used to look up an element in the container
    // the key also determines the position of the element
    
    // useful for storing information which we want to be able to search
    
    // a set is an unstructured collection of elements
    // an element of a set is a single data item consisting of a key
    // the key is used to check if the data item is present in the collection
    
    // a map is similar to a "directory" or a "hash map" in other languages
    // an element consists of a pair of data items, a key and a value
    // the key is used to search for an element and look up its value
    
    // associative containers don't support push_back() or push_front()
    // - the position of an element is determined by its key
    
    // associative containers do support many container operations
    // - insert() to add an element, erase() to erase an element
    // - we can use iterators to loop over the container
    // - they have member functions which are similar to generic algorithms
    
    // container adaptors

    // these are data structures (queues and stacks) which are implemented using sequential containers
    // - data is stored in these containers in an order which depends on when the data was added
    
    // Associative containers & Custom Types example
    std::multimap<std::string, Book> library;
 
    return 0;
}
