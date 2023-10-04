#include "../headers/classes.h"
#include "../headers/helper.h"

bool is_operator(char c){
    static const std::unordered_set<char> operators = {'+', '-', '*', '/', '%', '^'};
    return operators.find(c) != operators.end();
}

bool is_in_DIGITS(char num){
    for(int i = 0; i <= 9; i++){
        if(num == DIGITS[i]){
            return true;
        }
    }
    return false;
}