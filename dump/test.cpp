class Lexer{
    private:

    char curr_ch;
    int pos;
    int line;

    bool is_in_DIGITS(char num){
        for(int i = 0; i <= 9; i++){
            if(num == DIGITS[i]){
                return true;
            }
        }
        return false;
    }

    void advance(){
        this->pos += 1;  
        if(this->pos < sizeof(this->content)/sizeof(char)){
            this->curr_ch = this->content[pos];
            return;
        }
        return;
    }
    std::any make_number(){
        std::string number;
        int dot_count = 0;
        while((this->curr_ch != '\0' && this->is_in_DIGITS(this->curr_ch)) || this->curr_ch == '.'){
            if(this->curr_ch == '.'){
                if(dot_count == 1){
                    Illegal_Float_Digit_Error err('.', this->line, this->pos);
                    err.show_error();
                    break;
                }   
                dot_count += 1;
                number += '.';
            }
            else{
                number += this->curr_ch;
            }
            this->advance();
        }
        if(dot_count > 0){
            std::any num = std::stof(number);
            return num;
        }
        std::any num = std::stoi(number);
        return num;
    }

    public:

    std::vector<std::any>TT;
    std::string content;
    std::ifstream file;

    Lexer(std::string input){
        this->line = 1;
        this->pos = -1;
        this->curr_ch = '\0';
        open(input);
        this->advance();
    }

    // change the return type to vector after
    void make_vector(){
        // std::vector<std::string> token;
        while(this->curr_ch != '\0'){
            if(this->curr_ch == TT_NEXT_LINE){
                this->TT.push_back(TT_NEXT_LINE);
                this->advance();
                this->line += 1;
            }
            else if(this->is_in_DIGITS(this->curr_ch) == true){
                this->TT.push_back(this->make_number());
            }
            else if(this->curr_ch == TT_PLUS){
                this->TT.push_back(TT_PLUS);
                this->advance();
            }
            else if(this->curr_ch == TT_MINUS){
                this->TT.push_back(TT_MINUS);
                this->advance();
            }
            else if(this->curr_ch == TT_MULTIPLY){
                this->TT.push_back(TT_MULTIPLY);
                this->advance();
            }
            else if(this->curr_ch == TT_ASSGINMENT){
                this->TT.push_back(TT_ASSGINMENT);
                this->advance();
            }
            else if(this->curr_ch == TT_DIVIDE){
                this->TT.push_back(TT_DIVIDE);
                this->advance();
            }
            else if(this->curr_ch == TT_REMAINDER){
                this->TT.push_back(TT_REMAINDER);
                this->advance();
            }
            else if(this->curr_ch == TT_POWER){
                this->TT.push_back(TT_POWER);
                this->advance();
            }
            else{
                char err_char = this->curr_ch;
                this->advance();
                Illegal_Char_Error err(err_char, this->line, this->pos);
                err.show_error();
                // throw std::runtime_error("Invaild character!");
                return;
            }
        }
    }

    void open(std::string input){
        std::stringstream buffer;
        std::ifstream obj;
        obj.open(input);
        if(!obj.is_open()){
            throw std::runtime_error("Can not open the file.");
        }
        buffer << obj.rdbuf();
        this->content = buffer.str();
        this->file.close();
        return;
    }
};