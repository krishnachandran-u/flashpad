#include <ctype.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include "include/error_handling.h"

struct termios originalTermios;

void disableRawMode() {
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios) == -1) die("tcsetattr");
}

void enableRawMode() {
    if(tcgetattr(STDIN_FILENO, &originalTermios) == -1) die("tcgetattr");
    struct termios rawTermios = originalTermios;
    
    rawTermios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    rawTermios.c_iflag &= ~(OPOST);
    rawTermios.c_iflag &= ~(CS8);
    rawTermios.c_lflag &= ~(ECHO | ICANON | ISIG); 
    rawTermios.c_cc[VMIN] = 0;
    rawTermios.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &rawTermios) == -1) die("tcsetattr");
}

int main() {
    enableRawMode();
    atexit(disableRawMode);

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
