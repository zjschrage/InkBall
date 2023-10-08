# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++2a -Wall -Iinclude
DEBUG := -g
SFML := -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Source files and corresponding object files
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Target executable
TARGET := $(BIN_DIR)/inkball

# Define REPLAY_ON conditionally
ifdef REPLAY
MACRO_FLAGS := -DREPLAY_ON
else
MACRO_FLAGS :=
endif

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(SFML) $(DEBUG) $(MACRO_FLAGS) -c $< -o $@

# Rule to build the executable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(SFML) $(DEBUG) $^ -o $@

# Clean up object and executable files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
