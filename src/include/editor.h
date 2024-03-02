#ifndef EDTOR_H
#define EDITOR_H

#define CTRL_KEY(k) ((k) & 0x1f)

#include "buffer.h"

class Editor {
    public:
        Editor();
        char readKey();
        void handleKeyPress(); 
        void refresh();
        void draw();
        void moveCursor(char c);
        int getWindowSize(int* rows, int* cols);
        int getCursorPosition(int *rows, int *cols);
        ~Editor();
    private:
        int cx, cy;
        struct Parameters {
            int rows;
            int cols;
        };
        Parameters params;
        AppendBuffer ab;
};

#endif