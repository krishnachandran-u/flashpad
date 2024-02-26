#include <string>
#include <iostream>
#include "../include/editor.h"
#include "../include/errors.h"

void die(const std::string& s) {
    Editor editor;
    editor.refresh();

    std::cerr << s << std::endl;
    exit(1);
}