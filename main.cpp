#include <iostream>
#include "./headers/classes.h"

// Test
int main(int argc, char* argv[]){
    Lexer l1(argv[1]);
    l1.make_vector();
    Token t1(l1.TT);
    t1.repr();

    std::any left = '1';
    std::any op = '1';
    std::any right = '1';

    Bi_Op_Node node1(left, op, right);
    std::cout << node1.represent() << std::endl;
    return 0;
}
