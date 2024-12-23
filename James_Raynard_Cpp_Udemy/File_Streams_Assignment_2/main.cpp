#include <iostream>
#include <fstream>
#include <vector>

struct language {
    std::string lang;
    std::string designer;
    int date;
};

int main() {
    
    // languages2.txt into ifstream
    std::ifstream in_file {"file_location"};
    if (!in_file) {
        
        std::cout << "File couldn't read.";
        return 1;
    }
    
    std::vector<language> language_vector {};
    
    std::string line;
    while (!in_file.eof()) {
        
        // read the line
        getline(in_file, line);
        
        // last line is empty, causing a crash. bypass the last line
        if (line == "") break; 
        
        // obtain names from the line
        std::string lang_name;
        std::string lang_designer;
        std::string lang_date;
        
        // lang name
        for (size_t i=0; i<line.find(' '); ++i) {
            lang_name += line[i];
        }
        
        // lang date
        size_t temp = line.length()-1; 
        for (size_t i=temp; i>line.find_last_of(' '); i--) {
            lang_date += line[i];
        }
        
        std::string date_temp = lang_date;
        for (size_t i=0; i<date_temp.length(); ++i) {
            lang_date[i] = date_temp[date_temp.length()-1-i];
        }
        
        // lang designer
        size_t temp_start = line.find_first_of(' ')+1;
        size_t temp_end = line.find_last_of(' ');
        for (size_t i = temp_start; i < temp_end; ++i) {
            lang_designer += line[i];
        } 
        
        // create the lang object to push_back into language_vector
        language_vector.push_back( {lang_name, lang_designer, stoi(lang_date)} );
    }
    
    // print the elements of the vector
    for (language& el : language_vector) {
        std::cout << el.lang << " " << el.designer << " " << el.date << std::endl;
    }
    
	return 0;
}
