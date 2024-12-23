#include <iostream>
#include <string>
int main() {
    
    //• Without adding any extra backslashes, create a string variable which contains the following characters:
    // <a href="file">C:\"Program Files"\</a>\n
    std::string s {"<a href=\"file\">C:\\\"Program Files\"\\</a>\\n"};
    std::cout << s << std::endl;
    
    //Repeat this with the following characters: <a href="file">"C:\Program Files (x86)"\</a>\n
    s = "<a href=\"file\">C:\\\"Program Files (x86)\"\\</a>\\n";
    std::cout << s << std::endl;


	return 0;
}
