#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <any>
#include <unordered_set>
#include <cctype>
#include <typeinfo>

#define TT_POWER '^'
#define TT_ASSGINMENT '='
#define TT_PRINT "output"
#define TT_PLUS '+'
#define TT_MINUS '-'
#define TT_MULTIPLY '*'
#define TT_DIVIDE '/'
#define TT_REMAINDER '%'
#define TT_NEXT_LINE '\n'

// Perform opening the source file and make it into a vector so that the Token class 
class Token{
    private:
    
    public:

    std::vector<std::any> value;
    Token(std::vector<std::any>& v) : value(v){

    }
    void repr();
};

class Lexer{

    private:

    char curr_ch;
    int pos;
    int line;

    void advance();
    std::any make_number();

    public:

    std::vector<std::any>TT;
    std::string content;
    std::ifstream file;

    Lexer(std::string input) : curr_ch('\0'), pos(-1), line(1){
        this->open(input);
        this->advance();
    }

    void make_vector();

    void open(std::string input);

};

// Error handling class and its child classes
class Error_Handle{
    private:

    std::string name;
    char detail;
    int line;
    int position;

    public:

    Error_Handle(std::string n, char d, int l, int p) : name(n), detail(d), line(l), position(p){

    }

    void show_error();
};

class Illegal_Char_Error : public Error_Handle{
    private:

    public:

    Illegal_Char_Error(char d, int line, int position) : Error_Handle("Char_Error", d, line, position){

    }
};

class Illegal_Digit_Error : public Error_Handle{
    private:

    public:

    Illegal_Digit_Error(char d, int line, int position) : Error_Handle("Must be a type of digit", d, line, position){

    }
};

class Illegal_Float_Digit_Error : public Error_Handle{
    private:

    public:

    Illegal_Float_Digit_Error(char d, int line, int position) : Error_Handle("Type of float can only have one decimal point", d, line, position){

    }
};

class Number_Token{
    private:

    public:
};

class Bi_Op_Node{
    private:

    public:

    std::any left, op, right;

    Bi_Op_Node(std::any left, std::any op, std::any right) : left(left), op(op), right(right){

    }

    std::string represent();
};

class Parser{
    private:

    int token_index = -1;

    public:

    std::any current_token;
    std::vector<std::any> TT;
    std::string result;

    Parser(std::vector<std::any> TT) : TT(TT), result(""){

    }
 
    void advance();

    std::any factor();

    void term();
};
// class should retrun string to view the expression