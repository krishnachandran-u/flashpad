#ifndef EDTOR_H
#define EDITOR_H

#define CTRL_KEY(k) ((k) & 0x1f)

class Editor {
public:
    Editor();
    char readKey();
    void handleKeyPress(); 
    ~Editor();
};

#endif