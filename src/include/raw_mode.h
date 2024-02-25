#ifndef RAW_MODE_H 
#define RAW_MODE_H

#include <ctype.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "error_handling.h"

extern struct termios originalTermios;

void disableRawMode();
void enableRawMode();

#endif