#include <string>
#include <iostream>

#include "../include/errors.h"

void die(const std::string& s) {
    std::cerr << s << std::endl;
    exit(1);
}