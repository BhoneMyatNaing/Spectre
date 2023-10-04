#include "../headers/classes.h"
#include "../headers/helper.h"

std::string Bi_Op_Node::represent(){
    std::ostringstream formatted;
    formatted << '(' << std::any_cast<char>(this->left) << std::any_cast<char>(this->op) << std::any_cast<char>(this->right) << ')';
    return formatted.str();
}