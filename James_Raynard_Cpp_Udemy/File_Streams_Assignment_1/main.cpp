#include <iostream>
#include <fstream>
#include <vector>


struct language {
    std::string lang;
    std::string designer;
    int date;
};

int main() {
    
    // languages.txt into ifstream
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
        std::vector<std::string> temp_vec {};
        std::string temp_word {};
        
        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] != ' ') {
                temp_word += line[i];
            }
            else {
                temp_vec.push_back(temp_word);
                temp_word = "";
            }
        }
        temp_vec.push_back(temp_word);
        
        // print elements of temp_vec
        /*std::cout <<  "temp_vec elements: ";
        for (const auto& el : temp_vec) {
            std::cout << el << ",";
        }
        std::cout << std::endl;*/
        
        // create the lang object to push_back into language_vector
        language_vector.push_back( {temp_vec[0], temp_vec[1], stoi(temp_vec[2])} );
    }
    
    // print the elements of the vector
    for (language& el : language_vector) {
        std::cout << el.lang << ", " << el.designer << ", " << el.date << std::endl;
    }
    
	return 0;
}
