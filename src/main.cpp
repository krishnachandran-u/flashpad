#include <iostream>
#include <stdbool.h>

#include "include/errors.h"
#include "include/terminal_control.h"
#include "include/editor.h"

int main() {
    TerminalController tc;
    tc.enableRawMode();

    Editor editor;
    while(true) {
        editor.refresh();
        editor.handleKeyPress();
    }


    return 0;
}
