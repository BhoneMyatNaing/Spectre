class Error_Handle{
    private:

    std::string name;
    char detail;
    int line;
    int position;

    public:

    Error_Handle(std::string n, char d, int l, int p) : name(n), detail(d), line(l), position(p){

    }

    void show_error(){
        std::string retr = this->name + " : " + this->detail + "  " + "At line no: " + std::to_string(this->line) + " | position :" + std::to_string(this->position);
        throw std::runtime_error(retr);
    }
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