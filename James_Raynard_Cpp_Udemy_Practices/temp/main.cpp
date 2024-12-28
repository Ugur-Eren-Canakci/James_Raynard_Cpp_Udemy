#include <iostream>
#include <fstream>

int main() {
    
    std::string file_location{"C:\\Users\\ugur_\\Desktop\\Self Studies\\Cpp\\James_Raynard_Cpp_Udemy\\James_Raynard_Cpp_Udemy_Practices\\Algorithms_and_Iterators_Assignment\\output_file.txt"};
    std::ifstream in_file(file_location, std::ios::in);
    
    if (!in_file) {
        std::cout << "file read failed." << std::endl;
        return 1;
    }
    
    std::string line;
    while (!in_file.eof()) {
        getline(in_file, line);
        std::cout << line << std::endl;
    }    
	return 0;
}
