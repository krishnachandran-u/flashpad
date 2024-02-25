#ifndef RAW_MODE_H 
#define RAW_MODE_H

#include <ctype.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>

#include "error_handler.h"

class TerminalHandler {
    public:
        TerminalHandler();
        ~TerminalHandler();
        void disableRawMode();
        void enableRawMode();
    private:
        struct termios originalTermios;
        bool isRawModeEnabled;
};

#endif