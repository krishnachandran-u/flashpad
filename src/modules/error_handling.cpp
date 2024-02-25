#include <string>
#include <iostream>

void die(const std::string& s) {
    std::cerr << s << std::endl;
    exit(1);
}