#ifndef RAW_MODE_H 
#define RAW_MODE_H

#include <ctype.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "error_handling.h"

class RawModeHandler {
    public:
        RawModeHandler();
        ~RawModeHandler();
        void disableRawMode();
        void enableRawMode();
    private:
        struct termios originalTermios;
};

#endif