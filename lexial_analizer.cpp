#include "lexical_analizer.h"



Analizer::Analizer(std::ifstream &file):source_file(file){}

Analizer::~Analizer(){
    source_file.close();
}

void Analizer::run_analizer(){
    read_in_starting_state();
}


bool  Analizer::char_is_character(const char &ch) const {
    if (std::find(this->abc.begin(), this->abc.end(), ch)!=this->abc.end()){
        std::cout<<"ch is a character"<<std::endl;
        return true;
    }
    std::cout<<"ch is not a character"<<std::endl;
    return false;
}


bool Analizer::char_is_num(const char &ch) const{
    if (std::find(this->num.begin(), this->num.end(), ch)!=this->num.end()){
        return true;
    }

    return false;
}

void Analizer::error(std::string err_msg) const{
    std::cerr<<err_msg<<std::endl;
    this->~Analizer();
    exit(-1);
}



void Analizer::read_in_starting_state(){
    curr_char=this->source_file.get();
    std::cout<<curr_char<<std::endl;
    std::cout<<"Starting state"<<std::endl;     
    
    if (char_is_character(curr_char))
        read_in_identifier();
        
    else if (char_is_num(curr_char))
        read_in_number();

    else if (curr_char=='{')
        read_in_comment();

    else if (curr_char=='}') 
        error("There was no opening '{'");
    
    else if (curr_char=='(')
        read_in_found_opening_paranthesis();
    
    else if (curr_char=='*')
        error("Unexpected '*'");

    else if (curr_char==')')
        error("opening '(' missing");
    
    else if (curr_char==':')
        read_in_colon();

    else if (curr_char=='=')
        error("unecpected '='");

    else if (curr_char=='<')
        read_in_less_then();

    else if (curr_char=='>')
        read_in_bigger_then();

    else if (curr_char==' ')
        read_in_starting_state();
    
    else if (curr_char=='$')
        read_in_end_of_program();

    else
        error("Char is forbidden here");

}


void Analizer::read_in_identifier(){
    curr_char=source_file.get();    
    std::cout<<curr_char<<std::endl; 

    if (char_is_character(curr_char))
        read_in_identifier();

    else if (char_is_num(curr_char))
        read_in_identifier();

    else if (curr_char=='{')
        read_in_end_of_identifier();

    else if (curr_char=='}') 
        read_in_end_of_identifier();
    
    else if (curr_char=='(')
        read_in_end_of_identifier();
    
    else if (curr_char=='*')
        read_in_end_of_identifier();

    else if (curr_char==')')
        read_in_end_of_identifier();
    
    else if (curr_char==':')
        read_in_colon();

    else if (curr_char=='=')
        read_in_end_of_identifier();

    else if (curr_char=='<')
        read_in_end_of_identifier();

    else if (curr_char=='>')
        read_in_end_of_identifier();

    else if (curr_char==' ')
        read_in_end_of_identifier();
    
    else if (curr_char=='$')
        read_in_end_of_identifier();

    else
        read_in_end_of_identifier();
}


void Analizer::read_in_end_of_identifier(){
    source_file.putback(curr_char);
    std::cout<<curr_char<<std::endl; 
    read_in_starting_state();
}


void Analizer::read_in_number(){
    curr_char=source_file.get();
    std::cout<<curr_char<<std::endl; 

    if (char_is_character(curr_char))
        read_in_end_of_number();

    else if (char_is_num(curr_char))
        read_in_number();

    else if (curr_char=='{')
        read_in_end_of_number();

    else if (curr_char=='}') 
        read_in_end_of_number();
    
    else if (curr_char=='(')
        read_in_end_of_number();
    
    else if (curr_char=='*')
        read_in_end_of_number();

    else if (curr_char==')')
        read_in_end_of_number();
    
    else if (curr_char==':')
        read_in_end_of_number();

    else if (curr_char=='=')
        read_in_end_of_number();

    else if (curr_char=='<')
        read_in_end_of_number();

    else if (curr_char=='>')
        read_in_end_of_number();

    else if (curr_char==' ')
        read_in_end_of_number();
    
    else if (curr_char=='$')
        read_in_end_of_number();

    else
        read_in_end_of_number();
}

void Analizer::read_in_end_of_number(){
    source_file.putback(curr_char);
    std::cout<<curr_char<<std::endl; 
    read_in_starting_state();
}

void Analizer::read_in_comment(){
    curr_char=source_file.get();

    if (char_is_character(curr_char))
        read_in_comment();

    else if (char_is_num(curr_char))
        read_in_comment();

    else if (curr_char=='{')
        read_in_comment();

    else if (curr_char=='}') 
        read_in_end_of_comment();
    
    else if (curr_char=='(')
        read_in_comment();
    
    else if (curr_char=='*')
        read_in_comment();

    else if (curr_char==')')
        read_in_comment();
    
    else if (curr_char==':')
        read_in_comment();

    else if (curr_char=='=')
        read_in_comment();

    else if (curr_char=='<')
        read_in_comment();

    else if (curr_char=='>')
        read_in_comment();

    else if (curr_char==' ')
        read_in_comment();
    
    else if (curr_char=='$')
        read_in_comment();

    else
        read_in_comment();
}


void Analizer::read_in_end_of_comment(){
    read_in_starting_state();
}


void Analizer::read_in_found_opening_paranthesis(){
    curr_char=source_file.get();

    if (char_is_character(curr_char))
        read_in_correcting();

    else if (char_is_num(curr_char))
        read_in_correcting();

    else if (curr_char=='{')
        read_in_correcting();

    else if (curr_char=='}') 
        read_in_correcting();
    
    else if (curr_char=='(')
        read_in_correcting();
    
    else if (curr_char=='*')
        read_in_big_comment();

    else if (curr_char==')')
        read_in_correcting();
    
    else if (curr_char==':')
        read_in_correcting();

    else if (curr_char=='=')
        read_in_correcting();

    else if (curr_char=='<')
        read_in_correcting();

    else if (curr_char=='>')
        read_in_correcting();

    else if (curr_char==' ')
        read_in_correcting();
    
    else if (curr_char=='$')
        error("End of program isforbidden after '('");

    else
        read_in_correcting();
}

void Analizer::read_in_big_comment(){
    curr_char=source_file.get();

    if (char_is_character(curr_char))
        read_in_big_comment();

    else if (char_is_num(curr_char))
        read_in_big_comment();

    else if (curr_char=='{')
        read_in_big_comment();

    else if (curr_char=='}') 
        read_in_big_comment();
    
    else if (curr_char=='(')
        read_in_big_comment();
    
    else if (curr_char=='*')
        read_in_star_in_big_comment();

    else if (curr_char==')')
        read_in_big_comment();
    
    else if (curr_char==':')
        read_in_big_comment();

    else if (curr_char=='=')
        read_in_big_comment();

    else if (curr_char=='<')
        read_in_big_comment();

    else if (curr_char=='>')
        read_in_big_comment();

    else if (curr_char==' ')
        read_in_big_comment();
    
    else if (curr_char=='$')
        read_in_big_comment();

    else
        read_in_big_comment();
}

void Analizer::read_in_star_in_big_comment(){
    curr_char=source_file.get();

    if (char_is_character(curr_char))
        read_in_big_comment();

    else if (char_is_num(curr_char))
        read_in_big_comment();

    else if (curr_char=='{')
        read_in_big_comment();

    else if (curr_char=='}') 
        read_in_big_comment();
    
    else if (curr_char=='(')
        read_in_big_comment();
    
    else if (curr_char=='*')
        read_in_star_in_big_comment();

    else if (curr_char==')')
        read_in_end_of_big_comment();
    
    else if (curr_char==':')
        read_in_big_comment();

    else if (curr_char=='=')
        read_in_big_comment();

    else if (curr_char=='<')
        read_in_big_comment();

    else if (curr_char=='>')
        read_in_big_comment();

    else if (curr_char==' ')
        read_in_big_comment();
    
    else if (curr_char=='$')
        read_in_big_comment();

    else
        read_in_big_comment();
}


void Analizer::read_in_end_of_big_comment(){
    read_in_starting_state();
}

void Analizer::read_in_colon(){
    curr_char=source_file.get();

    if (char_is_character(curr_char))
        read_in_correcting();

    else if (char_is_num(curr_char))
        read_in_correcting();

    else if (curr_char=='{')
        read_in_correcting();

    else if (curr_char=='}') 
        read_in_correcting();
    
    else if (curr_char=='(')
        read_in_correcting();
    
    else if (curr_char=='*')
        read_in_correcting();

    else if (curr_char==')')
        read_in_correcting();
    
    else if (curr_char==':')
        read_in_correcting();

    else if (curr_char=='=')
        read_in_colon_equality();

    else if (curr_char=='<')
        read_in_correcting();

    else if (curr_char=='>')
        read_in_correcting();

    else if (curr_char==' ')
        read_in_correcting();
    
    else if (curr_char=='$')
        error("End of program is forbidden after ':'");

    else
        read_in_correcting();
}

void Analizer::read_in_colon_equality(){
    read_in_starting_state();
}


void Analizer::read_in_less_then(){
    curr_char=source_file.get();

    if (char_is_character(curr_char))
        read_in_correcting();

    else if (char_is_num(curr_char))
        read_in_correcting();

    else if (curr_char=='{')
        read_in_correcting();

    else if (curr_char=='}') 
        read_in_correcting();
    
    else if (curr_char=='(')
        read_in_correcting();
    
    else if (curr_char=='*')
        read_in_correcting();

    else if (curr_char==')')
        read_in_correcting();
    
    else if (curr_char==':')
        read_in_correcting();

    else if (curr_char=='=')
        read_in_less_then_or_equal();

    else if (curr_char=='<')
        read_in_correcting();

    else if (curr_char=='>')
        read_in_less_then_and_bigger_then();

    else if (curr_char==' ')
        read_in_correcting();
    
    else if (curr_char=='$')
        error("End of program is forbidden after '<'");

    else
        read_in_correcting();
}

void Analizer::read_in_less_then_or_equal(){
    read_in_starting_state();
}

void Analizer::read_in_less_then_and_bigger_then(){
    read_in_starting_state();
}

void Analizer::read_in_bigger_then(){
    curr_char=source_file.get();

    if (char_is_character(curr_char))
        read_in_correcting();

    else if (char_is_num(curr_char))
        read_in_correcting();

    else if (curr_char=='{')
        read_in_correcting();

    else if (curr_char=='}') 
        read_in_correcting();
    
    else if (curr_char=='(')
        read_in_correcting();
    
    else if (curr_char=='*')
        read_in_correcting();

    else if (curr_char==')')
        read_in_correcting();
    
    else if (curr_char==':')
        read_in_correcting();

    else if (curr_char=='=')
        read_in_bigger_then_or_equal();

    else if (curr_char=='<')
        read_in_correcting();

    else if (curr_char=='>')
        read_in_correcting();

    else if (curr_char==' ')
        read_in_correcting();
    
    else if (curr_char=='$')
        error("End of program is forbidden after '>'");

    else
        read_in_correcting();
}


void Analizer::read_in_bigger_then_or_equal(){
    read_in_starting_state();
}


void Analizer::read_in_correcting(){
    source_file.putback(curr_char);
    read_in_starting_state();
}


void Analizer::read_in_end_of_program(){
    std::cout<<"lexical analisis ha finished successfully"<<std::endl;
    this->~Analizer();
}