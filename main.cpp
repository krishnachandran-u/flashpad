#include <ctype.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

struct termios original_termios;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios); //reset
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &original_termios); 

    struct termios raw_termios = original_termios;
    
    raw_termios.c_lflag &= ~(ECHO | ICANON); 

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_termios); 
}

int main() {
    enableRawMode();

    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        if((iscntrl(c))) {
            std::cout << c << "\n";
        }
        else {
            std::cout << (int)c << " " << c << "\n";
        }
    }

    disableRawMode();
    return 0;
}
