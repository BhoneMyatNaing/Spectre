#include "../headers/classes.h"

void Error_Handle::show_error(){
    std::string retr = this->name + " : " + this->detail + "  " + "At line no: " + std::to_string(this->line) + " | position :" + std::to_string(this->position);
    throw std::runtime_error(retr);
}