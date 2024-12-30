// url.cpp
#include <iostream>
#include <string>
#include "url.h"

URL::URL(const std::string& prot, const std::string& res) {
	protocol = prot;
	resource = res;
}
	
void URL::print() const {
	std::cout << protocol << "://" << resource << "\n";
}

std::string URL::return_str() const{
    std::string res = this->protocol + ":\\" + this->resource;
    return res;
}