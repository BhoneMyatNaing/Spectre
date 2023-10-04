// For manual compiling, use the following command

g++ --std=gnu++17 main.cpp ./class_def/Token.cpp ./class_def/Lexer.cpp ./class_def/Error_Handle.cpp ./class_def/helper.cpp ./class_def/Node.cpp ./class_def/Parser.cpp -o a.exe

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))