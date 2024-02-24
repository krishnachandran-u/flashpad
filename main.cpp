#include <ctype.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <string>

struct termios original_termios;

void kill(const std::string& s) {
    std::cerr << s << std::endl;
    exit(1);
}

void disableRawMode() {
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios) == -1) kill("tcsetattr");
}

void enableRawMode() {
    if(tcgetattr(STDIN_FILENO, &original_termios) == -1) kill("tcgetattr");
    struct termios raw_termios = original_termios;
    
    raw_termios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw_termios.c_iflag &= ~(OPOST);
    raw_termios.c_iflag &= ~(CS8);
    raw_termios.c_lflag &= ~(ECHO | ICANON | ISIG); 
    raw_termios.c_cc[VMIN] = 0;
    raw_termios.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_termios) == -1) kill("tcsetattr");
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
