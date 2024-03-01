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
        int getWindowSize(int* rows, int* cols);
        int getCursorPosition(int *rows, int *cols);
        ~Editor();
    private:
        struct Parameters {
            int rows;
            int cols;
        };
        Parameters params;
        AppendBuffer ab;
};

#endif