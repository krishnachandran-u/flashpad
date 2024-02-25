#include <ctype.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>

#include "../include/error_handler.h"
#include "../include/terminal_control.h"

TerminalController:: TerminalController() {
    isRawModeEnabled = false;
    if(tcgetattr(STDIN_FILENO, &originalTermios) == -1) die("tcgetattr");
}

void TerminalController::enableRawMode() {
    struct termios rawTermios = originalTermios;
    
    rawTermios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    rawTermios.c_iflag &= ~(OPOST);
    rawTermios.c_iflag &= ~(CS8);
    rawTermios.c_lflag &= ~(ECHO | ICANON | ISIG); 
    rawTermios.c_cc[VMIN] = 0;
    rawTermios.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &rawTermios) == -1) die("tcsetattr");

    isRawModeEnabled = true;
}

void TerminalController::disableRawMode() {
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios) == -1) die("tcsetattr");

    isRawModeEnabled = false;
}

TerminalController::~TerminalController() {
    if(isRawModeEnabled){
        disableRawMode();
    }
}

