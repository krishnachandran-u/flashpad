#include <string>
#include <sstream>

#include "../include/buffer.h"

AppendBuffer::AppendBuffer() {}

void AppendBuffer::append(const std::string& s) {
    buffer << s;
}

std::string AppendBuffer::getBuffer() const {
    return buffer.str();
}

AppendBuffer::~AppendBuffer() {}