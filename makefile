CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic 

SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

SRC_EXT = cpp
OBJ_EXT = o

SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))

OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT)))

TARGET = $(BIN_DIR)/bonsai

.PHONY: all clean run_all

all: $(TARGET)

run_all: clean all run

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $(TARGET)

$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	$(TARGET)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

-include $(OBJECTS:.o=.d)