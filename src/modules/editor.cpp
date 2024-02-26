#include "../include/editor.h"
#include <unistd.h>
#include <errno.h>
#include "../include/errors.h"

Editor::Editor() {}

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

Editor::~Editor() {}