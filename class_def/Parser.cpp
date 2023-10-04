#include "../headers/classes.h"
#include "../headers/helper.h"

void Parser::advance(){
    this->token_index += 1;
    if(this->token_index < this->TT.size()){
        this->current_token = this->TT[this->token_index];
    }
}

std::any Parser::factor(){
    std::any tok = this->current_token;
    if(this->current_token.type() == typeid(int) || this->current_token.type() == typeid(float)){
        this->advance();
    }
    return tok;
}

void Parser::term(){
    std::any left = this->factor();
    while(this->current_token.type() == typeid(char) && is_operator(std::any_cast<char>(this->current_token))){
        std::any op= this->current_token;
        std::any right = this->factor();
        Bi_Op_Node temp(left, op, right);
        this->result += temp.represent();
    }
}