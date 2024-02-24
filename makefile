CXX = g++
CXXVERSION = -std=c++20
CXXFLAGS = -Wall -Wextra -Wpedantic 

SRC = main.cpp
TARGET = main

.PHONY: all build run clean

all: build run

build: $(SRC)
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: build
	./$(TARGET)

clean:
	rm -rf $(TARGET)
