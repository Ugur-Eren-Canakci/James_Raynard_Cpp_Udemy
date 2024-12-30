#include <iostream>
#include "url.h"
#include <string>
#include <list>

class Class {
private:
    std::list<URL> list;
public:
    void add_url(const URL& url) {
        bool check = true;
        for (const URL& el : this->list) {
            if (el.return_str() == url.return_str()) check = false;
        }
        
        if (check) {
            list.push_front(url);
            std::cout << "url was added successfully." << std::endl;
        }
        else {
            std::cout << "url already in list." << std::endl;
        }
        
    }
    
    void print_list() {
        std::cout << "URL List:\n";
        for (const URL& el : this->list) {
            el.print();
        } 
    }
};

int main() {
    
    URL url("http", "example.com/index.html");
	url.print();
    std::cout << "url: " << url.return_str() << std::endl << std::flush;
    
    // Write a class which uses an STL container to store objects of your URL class. 
    // New objects are added at the front of the container.
    Class obj;
    obj.add_url(url);
    obj.add_url(URL{"https", "url.com/index.html"});
    obj.add_url(URL{"https", "url.com/index.html"});
    obj.print_list();
    
	return 0;
}
