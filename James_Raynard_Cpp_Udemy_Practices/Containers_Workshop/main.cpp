#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>


class URL {
private:
    std::string protocol;
    std::string domain;
public:
    
    URL(std::string p, std::string d) : protocol{p}, domain{d} {}
    
    URL() : protocol("http"), domain("") {}
    
    std::string get_url() const{
        return protocol + ":\\" + domain;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const URL& url) {
        os << url.protocol << ":\\" << url.domain << std::endl << std::flush;
        return os;
    }
};

class Library {
private:
    std::deque<URL> deque;
public:
    Library() {
        std::cout << "Library object initialized." << std::endl;
    }
    
    void add_website(const URL& url) {
        
        if (deque.size() == 0) deque.push_back(url);
        else {
            auto it = std::remove_if(deque.begin(), deque.end(), [&url] (URL temp) { return temp.get_url() == url.get_url(); } );
            if (it != deque.end()) deque.erase(it);
            deque.push_front(url);
        }
    }
    void print_history() {
        std::cout << "printing history" << std::endl;
        for (auto el : deque) {
            std::cout << el << std::flush;
        }
    }
};

template <typename T>
bool take_choice(const T& container) {
    bool repeat = true;
    while (repeat) {
        std::cout << "If you want to continue, enter 1." << std::endl;
        std::cout << "If you want to see all stored strings, enter 2." << std::endl;
        std::cout << "If you want to finish the program, enter 3." << std::endl;
        std::cout << "Choice: ";
        std::string choice;
        std::cin >> choice;
        if (choice == "1") {
            return true;
        }
        else if (choice == "2") {
            std::cout << "Stored strings: ";
            for (const std::string& el : container) std::cout << el << ",";
            std::cout << std::endl;
        }
        
        else if (choice == "3") {
            return false;
        }
        else {
            std::cout << "Invalid input. Try again." << std::endl;
            std::cin.clear();
        }
    }
}

void vec_program() {
    
    std::vector<std::string> vec;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "Please enter 's' to start: ";
    char user_input;
    std::cin >> user_input;
    
    bool flag_1 = false;
    if (user_input == 's') flag_1 = true;
    while (flag_1) {

        std::cin.clear();
        std::cout << "Please enter a string to store in memory: ";
        std::string temp_1;
        std::cin >> temp_1;
        
        vec.push_back(temp_1);
        std::cout << temp_1 << " successfully stored in memory." << std::endl;
        std::cin.clear();
            
        flag_1 = take_choice<std::vector<std::string>>(vec);
    }
    std::cout << "Thank you!";
}

void list_program() {
    
    std::list<std::string> list;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "Please enter 's' to start: ";
    char user_input;
    std::cin >> user_input;
    
    bool flag_1 = false;
    if (user_input == 's') flag_1 = true;
    while (flag_1) {

        std::cin.clear();
        std::cout << "Please enter a string to store in memory: ";
        std::string temp_1;
        std::cin >> temp_1;
        
        list.push_back(temp_1);
        std::cout << temp_1 << " successfully stored in memory." << std::endl;
        std::cin.clear();
            
        flag_1 = take_choice<std::list<std::string>>(list);
    }
    std::cout << "Thank you!";
}

void deque_program() {
    
    std::deque<std::string> deque;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "Please enter 's' to start: ";
    char user_input;
    std::cin >> user_input;
    
    bool flag_1 = false;
    if (user_input == 's') flag_1 = true;
    while (flag_1) {

        std::cin.clear();
        std::cout << "Please enter a string to store in memory: ";
        std::string temp_1;
        std::cin >> temp_1;
        
        deque.push_back(temp_1);
        std::cout << temp_1 << " successfully stored in memory." << std::endl;
        std::cin.clear();
            
        flag_1 = take_choice<std::deque<std::string>>(deque);
    }
    std::cout << "Thank you!";
}

void list_program_reverse() {
    
    std::list<std::string> list;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "Please enter 's' to start: ";
    char user_input;
    std::cin >> user_input;
    
    bool flag_1 = false;
    if (user_input == 's') flag_1 = true;
    while (flag_1) {

        std::cin.clear();
        std::cout << "Please enter a string to store in memory: ";
        std::string temp_1;
        std::cin >> temp_1;
        
        if (list.size() == 0) list.push_back(temp_1);
        else list.push_front(temp_1);
        std::cout << temp_1 << " successfully stored in memory." << std::endl;
        std::cin.clear();
            
        flag_1 = take_choice<std::list<std::string>>(list);
    }
    std::cout << "Thank you!";
}

void deque_program_reverse() {
    
    std::deque<std::string> deque;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "Please enter 's' to start: ";
    char user_input;
    std::cin >> user_input;
    
    bool flag_1 = false;
    if (user_input == 's') flag_1 = true;
    while (flag_1) {

        std::cin.clear();
        std::cout << "Please enter a string to store in memory: ";
        std::string temp_1;
        std::cin >> temp_1;
        
        if (deque.size() == 0) deque.push_back(temp_1);
        else deque.push_front(temp_1);
        std::cout << temp_1 << " successfully stored in memory." << std::endl;
        std::cin.clear();
            
        flag_1 = take_choice<std::deque<std::string>>(deque);
    }
    std::cout << "Thank you!";
}

void library_program() {
    // Define a class to hold an ordered history of URLs (as might be used in a web browser). 
    // Use an STL container to store the URLs
    
    // Ensure that a URL is added to the history only if it is not in the history already. 
    // If it is, it should be moved to the beginning of the history

    Library web_history;
    
    // Write a program to exercise your class
    std::vector<std::string> domain_list;
    for (int i=0; i<10; i++) {
        std::string temp_1 = std::to_string(i);
        std::string temp_2 = "url_" + temp_1 + ".com";
        domain_list.push_back(temp_2);
    }
    
    for (auto el : domain_list) {
        URL temp("http", el);
        web_history.add_website(temp);
    }
    
    URL website_1{"http", "url_0.com"};
    web_history.add_website(website_1);
    web_history.print_history();
    
    URL website_2{"http", "url_3.com"};
    web_history.add_website(website_2);
    web_history.print_history();
}

void set_program() {
    std::set<std::string> set;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "Please enter 's' to start: ";
    char user_input;
    std::cin >> user_input;
    
    bool flag_1 = false;
    if (user_input == 's') flag_1 = true;
    while (flag_1) {

        std::cin.clear();
        std::cout << "Please enter a unique string to store in memory: ";
        std::string temp_1;
        std::cin >> temp_1;
        
        set.insert(temp_1);
        std::cout << temp_1 << " successfully stored in memory." << std::endl;
        std::cin.clear();
            
        flag_1 = take_choice<std::set<std::string>>(set);
    }
    std::cout << "Thank you!";
}

void text_program() {
    
    /*
     * an istream_iterator is created in a similar way
        istream_iterator<int> ii(cin); -> iterator set on cin => will return data from cin
        
        when we dereference ii, it will return the current data
            int x = *ii;
            std::cout << "You entered " << x << std::endl;
        
        to read multiple input, we use a loop
            when dealing with input we have to know when to stop reading
                the iterator will be empty when there's no more input
                we can detect the end of input by comparing our iterator to an empty iterator
                we can create an empty iterator by not binding it to any stream
                    istream_iterator<string> eof; -> empty iterator
                    
            Ex:
            istream_iterator<string> iis(cin);
            istream_iterator<string> eof;
            vector<string> vs;
            while (!iis == eof) {
                vs.push_back(*iis);
                iis++;
            }
            
            for (auto v: vs) {
                cout << v << endl;
            }
            
            
     * */
    
    
    std::set<std::string> s;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "This program displays the number of distinct words in texts you will enter." << std::endl;
    std::cout << "Please enter a string: ";
    std::string line;
    std::getline(std::cin, line);
    std::cout << "You entered: " << line << std::endl;
    
    std::string word{""};
    for (size_t i=0; i<line.length(); i++) {
        if (line[i] == ' ') {
            s.insert(word);
            word = "";
        }
        else if (i == line.length() - 1) {

            word += line[i];
            std::cout << "final word: " << word << std::endl;
            s.insert(word);
        }
        else {
            word += line[i];
        }
    }
    
    std::cout << "Distinct words: [";
    for (const std::string& el : s) {
        std::cout << el << " ";
    }
    std::cout << "]" << std::endl;
}

void map_program() {

    std::vector<std::pair<std::string,size_t>> v;
    std::map<std::string, size_t> m;
    std::cout << "Welcome to the program!\n====================================" << std::endl;
    std::cout << "This program displays the number of distinct words in texts you will enter." << std::endl;
    std::cout << "Please enter a string: ";
    std::string line;
    std::getline(std::cin, line);
    std::cout << "You entered: " << line << std::endl;
    
    std::string word{""};
    for (size_t i=0; i<line.length(); i++) {
        if (line[i] == ' ') {
            size_t word_size = word.length();
            auto pair = std::pair<std::string, size_t>(word,word_size);
            v.push_back(pair);
            m.insert(pair);
            word = "";
        }
        else if (i == line.length() - 1) {

            word += line[i];
            std::cout << "final word: " << word << std::endl;
            size_t word_size = word.length();
            auto pair = std::pair<std::string, size_t>(word,word_size);
            v.push_back(pair);
            m.insert(pair);
        }
        else {
            word += line[i];
        }
    }
    
    std::cout << "Distinct words: [";
    for (const auto& el : m) {
        std::cout << el.first << "(length:" << el.second << "),";
    }
    std::cout << "]" << std::endl;
    
    std::cout << "All words: [";
    for (const auto& el : v) {
        std::cout << el.first << "(length:" << el.second << "),";
    }
    std::cout << "]" << std::endl;
}


class Family {
private:
    std::vector<std::string> children;
public:
    Family() {
        std::cout << "Family created." << std::endl;
    }
    
    void add_child(const std::string& child_name) {
        children.push_back(child_name);
    }
    
    void children_list() {
        std::cout << "Children's names: [";
        for (const std::string& el : children) {
            std::cout << el << ",";
        }
        std::cout << "]" << std::endl;
    }
};

void family_program() {
    
    std::map<std::string,Family> map;
    std::cout << "Welcome to the family program!" << std::endl;
    std::cout << "Please press 's' to start: ";
    char user_input;
    std::cin >> user_input;
    bool flag_1 = (user_input == 's') ? true : false;
    while (flag_1) {
        
        bool flag_2 = false;
        std::cin.clear();
        std::string family_name;
        std::cout << "Enter family name: ";
        if (std::cin >> family_name) flag_2 = true;
        Family current_family;
        while (flag_2) {
            
            char temp_input;
            
            std::cout << "If you want to add a child, enter 1." << std::endl;
            std::cout << "If you want to add another family, enter 2." << std::endl;
            std::cout << "If you want to stop, enter 3." << std::endl;
            std::cin >> temp_input;
            
            if (temp_input == '1') {
                flag_2 = true;
                std::string child_name;
                std::cout << "Enter child name: ";
                std::cin.ignore();
                getline(std::cin,child_name);
                current_family.add_child(child_name);
                std::cout << child_name << " was added to the " << family_name << " family." << std::endl;
            }
            else if (temp_input == '2') {
                map.insert(std::pair<std::string, Family>{family_name, current_family});
                flag_2 = false;
            }
            else if (temp_input == '3') {
                map.insert(std::pair<std::string, Family>{family_name, current_family});
                flag_2 = false;
                flag_1 = false;
            }
            else {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
    }
    std::cout << "Recorded families:" << std::endl;
    for (auto& el : map) {
        std::cout << "Family name: " << el.first << std::endl;
        el.second.children_list();
        std::cout << std::endl;
    }
}

void multimap_program() {
    
    std::multimap<std::string, std::string> m;
    std::cout << "Welcome to the family program!" << std::endl;
    std::cout << "Please press 's' to start: ";
    char user_input;
    std::cin >> user_input;
    bool flag_1 = (user_input == 's') ? true : false;
    while (flag_1) {
        
        bool flag_2 = false;
        std::cin.clear();
        std::string family_name;
        std::cout << "Enter family name: ";
        if (std::cin >> family_name) flag_2 = true;
        while (flag_2) {
            
            char temp_input;
            std::cout << "If you want to add a child, enter 1." << std::endl;
            std::cout << "If you want to add another family, enter 2." << std::endl;
            std::cout << "If you want to stop, enter 3." << std::endl;
            std::cin >> temp_input;
            
            if (temp_input == '1') {
                flag_2 = true;
                std::string child_name;
                std::cout << "Enter child name: ";
                std::cin.ignore();
                getline(std::cin,child_name);
                std::pair<std::string, std::string> pair{family_name, child_name};
                m.insert(pair);
                std::cout << child_name << " was added to the " << family_name << " family." << std::endl;
            }
            else if (temp_input == '2') {
                flag_2 = false;
            }
            else if (temp_input == '3') {
                flag_2 = false;
                flag_1 = false;
            }
            else {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
    }
    
    // Print families and the children
    auto it = m.begin();
    while (it != m.end()) {
        std::cout << "Family name: " << it->first <<", children: ";
        for (auto it_2 = m.lower_bound(it->first); it_2 != m.upper_bound(it->first); it_2++) {
            std::cout << it_2->second << ", ";
        }
        std::cout << std::endl;
        it = m.upper_bound(it->first);
    }
    
}

void unordered_multimap_program() {
    
    std::unordered_multimap<std::string, std::string> m;
    std::cout << "Welcome to the family program!" << std::endl;
    std::cout << "Please press 's' to start: ";
    char user_input;
    std::cin >> user_input;
    bool flag_1 = (user_input == 's') ? true : false;
    while (flag_1) {
        
        bool flag_2 = false;
        std::cin.clear();
        std::string family_name;
        std::cout << "Enter family name: ";
        if (std::cin >> family_name) flag_2 = true;
        while (flag_2) {
            
            char temp_input;
            std::cout << "If you want to add a child, enter 1." << std::endl;
            std::cout << "If you want to add another family, enter 2." << std::endl;
            std::cout << "If you want to stop, enter 3." << std::endl;
            std::cin >> temp_input;
            
            if (temp_input == '1') {
                flag_2 = true;
                std::string child_name;
                std::cout << "Enter child name: ";
                std::cin.ignore();
                getline(std::cin,child_name);
                std::pair<std::string, std::string> pair{family_name, child_name};
                m.insert(pair);
                std::cout << child_name << " was added to the " << family_name << " family." << std::endl;
            }
            else if (temp_input == '2') {
                flag_2 = false;
            }
            else if (temp_input == '3') {
                flag_2 = false;
                flag_1 = false;
            }
            else {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
    }
    
    // Print families and the children
    auto it = m.begin();
    while (it != m.end()) {
        std::cout << "Family name: " << it->first <<", children: ";
        int count = m.count(it->first);
        auto it_2 = m.find(it->first);
        for (int i=0; i<count; i++) {
            std::cout << it_2->second << ", ";
            it_2++;
            it++;
        }
        std::cout << std::endl;
    }
    
}

int main() {
    
    
    //library_program();
    
    // Write a program that reads strings entered by the user, stores them in a vector and 
    // prints out the strings in the order they were entered

    //vec_program();
    //list_program();
    //deque_program();
    //list_program_reverse();
    //deque_program_reverse();
    
    
    // Which sequential container would you use for:
    
    // A databank of historical securities prices, in chronological order. Numerical
    // processing will be repeatedly performed on the container and this must be
    // done efficiently. The prices may occasionally be altered (to correct bad data)
    // but will never be added to or removed
    // =>
    // My answer: array<double,whatever_size> 
    // No add/remove => fixed container size => array
    
    // A queue of people entering a venue. People join at the back of the queue and
    // leave, in arrival order, from the front. There should be provision for "VIP's" to
    // go straight to the front of the queue
    // =>
    // My answer: list<Person>
    // VIP's have to go the front => push_front is necessary
    // Also, random access is not needed as people will be added or removed purely based on where they
    // are on the list, not based on their respective values
    
    // Storing users who are connected to a very busy website. The users will be
    // added when they log on and removed when they log off (or are timed out)
    // =>
    // My answer: vector<User>
    // Random access is needed as we need to check their status frequently
    // Also, there's no need to have "adding a front element" functionality as timeouts are a thing.
    
    //Write a program that reads strings entered by the user, stores them in a set and prints out the strings
    //set_program();
    // What happens if the user enters duplicate strings?
    // duplicate strings are discarded. Only one copy of every object can be in a set
    
    //Write a program that displays the number of distinct words in some text using a set
    //text_program();
    
    /*
     * Write a program that reads words from input
    • Store the value and length of each word in a suitable std::pair
    • Store each pair in
    • A vector
    • A map whose key and value have the appropriate types
    • Print out all the elements of the vector and the map
     * */
    //map_program();
    
    
    
    /*
     * • Write a Family class which has
    • A vector of children's names as a member
    • A member function to add a child
    • A member function to print out all the children in the family
    • Define a map whose key is a family name and whose value is a Family
    • Write a program which populates this map and prints each family's
    name followed by its children's names
    * */
    //family_program();
    
    /*Define a multimap whose key is a family name and whose value is a
    child's name (i.e., one element per child)
    • Write a program which populates this multimap and prints each
    family's name followed by its children's names
    • Modify this program to use an unordered_multimap
    */
    multimap_program();
    
    //Modify this program to use an unordered_multimap
    unordered_multimap_program();
    return 0;
}
