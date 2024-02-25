#include <string>
#include <iostream>

#include "../include/error_handler.h"

void die(const std::string& s) {
    std::cerr << s << std::endl;
    exit(1);
}