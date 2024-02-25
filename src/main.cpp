#include <iostream>

#include "include/error_handler.h"
#include "include/terminal_control.h"

int main() {
    TerminalController tc;
    tc.enableRawMode();

    while(true) {
        char c = '\0';
        read(STDIN_FILENO, &c, 1);
        if((iscntrl(c))) {
            std::cout << static_cast<int>(c) << std::endl; //control characters doesnot have character definitions
        }
        else {
            std::cout << static_cast<int>(c) << ' ' << "(\'" << c << "\')" << std::endl;
        }
    }

    return 0;
}
