#include "../include/editor.h"
#include <unistd.h>
#include <errno.h>
#include "../include/errors.h"
#include <sys/ioctl.h>
#include <stdio.h>

Editor::Editor() {
    if(getWindowSize(&params.rows, &params.cols) == -1) die("getWindowSize");
}

char Editor::readKey() {
    int status;
    char c;
    while((status = read(STDIN_FILENO, &c, 1) != -1) != 1) { // status != 1 => cannot read
        if(status == -1 && errno != EAGAIN) { // status == 0 => EOF; status == -1 && errno != EAGAIN => fail 
            die("read");
        }
    }
    return c;
}

void Editor::handleKeyPress() {
    char c = readKey();

    //controls
    switch(c) {
        case CTRL_KEY('q'): 
            die("quit");
            break;
    }

    return;
}

void Editor::refresh() {
    write(STDOUT_FILENO, "\x1b[2J", 4); //clear the screen
    write(STDOUT_FILENO, "\x1b[H", 3); //position cursor to home
    draw();
    write(STDOUT_FILENO, "\x1b[H", 3);

    return;
}

void Editor::draw() {
    int y;
    for(y = 0; y < params.rows; y++) {
        write(STDOUT_FILENO, "~", 1);
        if(y < params.rows - 1) { //avoid newline in the last line when drawing as the cursor will overthrow
            write(STDOUT_FILENO, "\r\n", 2);
        }
    }
    return;
}

int Editor::getWindowSize(int* rows, int* cols) {
    struct winsize ws;
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) { // check if it is possible to retrive window size via ioctl
        if(write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) return -1; //go rightmost go downmost
        return getCursorPosition(rows, cols);
    }
    else {
        *rows = ws.ws_col;
        *cols = ws.ws_col;
        return 0;
    }
}

int Editor::getCursorPosition(int* rows, int* cols) {
    char buffer[64];
    long unsigned int i = 0;

    if(write(STDOUT_FILENO, "x1b[6n", 4) != 4) return -1;

    while(i < sizeof(buffer) - 1) {
        if(read(STDIN_FILENO, &buffer[i], 1) != 1) break;
        if(buffer[i] == 'R') // "x1b[6n" queries <esc>[rows;colsR
        i++;
    }

    buffer[i] = '\0';

    if(buffer[0] != '\x1b' || buffer[1] != '[') return -1;
    if(sscanf(&buffer[2], "%d;%d", rows, cols) != -1) return -1;

    return 0;
}

Editor::~Editor() {}