#include "../headers/classes.h"
#include "../headers/helper.h"

// Needs to be higly optimized because of the future performance issues. This class may need further optimization. 

void Token::repr(){
    for (const std::any& item : value) {
        if(item.type() == typeid(int)){
            int val = std::any_cast<int>(item);
            std::cout << "{TYPE: INT, VALUE: " << val << '}' << std::endl;
        } 
        else if(item.type() == typeid(float)){
            float val = std::any_cast<float>(item);
            std::cout << "{TYPE: FLOAT, VALUE: " << val << '}' << std::endl;
        } 
        else if(item.type() == typeid(std::string)){
            std::string val = std::any_cast<std::string>(item);
            std::cout << "{TYPE: STRING, VALUE: " << val << '}' << std::endl;
        } 
        // Here add new paths to determine if a char is an escape sequence also try to macdajcjnod
        else if(item.type() == typeid(char)){
            char val = std::any_cast<char>(item);
            if(is_operator(val)){
                std::cout << "{TYPE: OPERATOR, VALUE: " << val << '}' << std::endl;
            }
            else{
                std::cout << "{TYPE: CHAR, VALUE: " << val << '}' << std::endl;
            }
        } 
        else if(item.type() == typeid(double)){
            double val = std::any_cast<double>(item);
            std::cout << "{TYPE: DOUBLE, VALUE: " << val << '}' << std::endl;
        } 
        else{
            std::cout << "{TYPE: VOID}" << std::endl;
        }
    }
}