# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Directories
SRC_DIR = ./class_def
OBJ_DIR = ./obj
BIN_DIR = ./bin

# Source files
SRCS = main.cpp \
       $(SRC_DIR)/Token.cpp \
       $(SRC_DIR)/Lexer.cpp \
       $(SRC_DIR)/Error_Handle.cpp \
       $(SRC_DIR)/helper.cpp \
       $(SRC_DIR)/Node.cpp \
       $(SRC_DIR)/Parser.cpp

# Object files (automatically generated from source files)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET = $(BIN_DIR)/test.exe

# Default target (the one that will be built if you just type "make" without arguments)
all: $(TARGET)

# Create directories if they don't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Linking the object files to create the target executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation rules for each source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up object files and the target executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
