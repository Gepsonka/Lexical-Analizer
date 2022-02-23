#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

#ifndef ANALIZER
#define ANALIZER

class Analizer{

    // enum States {
    //     STARTING_STATE=1,
    //     IN_IDENTIFIER=2,
    //     END_OF_IDENTIFIER=3,
    //     IN_NUMBER=4,
    //     END_OF_NUMBER=5,
    //     IN_COMMENT=6, // {}
    //     END_OF_COMMENT=7, // {}
    //     FOUND_OPENING_PARANTHESIS=8, // (
    //     IN_BIG_COMMENT=9, // (**)
    //     STAR_IN_BIG_COMMNET=10, // (**)
    //     END_OF_BIG_COMMENT=11, // (**)
    //     COLON=12, // :
    //     COLON_EQUALITY=13, // := 
    //     LESS_THEN=14, // <
    //     LESS_THEN_OR_EQUAL=15, // <=
    //     LESS_THEN_AND_BIGGER_THEN=16, // <>
    //     BIGGER_THEN=17, // >
    //     BIGGER_THEN_OR_EQUAL=18, // >=
    //     ERROR=19, // err
    //     CORRECTING=20,
    //     END_OF_PROGRAM=21 // $
    // };

    std::vector<char> stack;
    char curr_char;
    // States curr_state;
    std::ifstream &source_file;

    const std::vector<char> num={'0','1','2','3','4','5','6','7','8','9'};

    const std::vector<char> abc={'a','b','c','d','e','f','g','h',
                            'i','j','k','l','m','n','o','p','q',
                            'r','s','t','u','v','w','x','y','z'};

    
    bool char_is_character(const char &ch) const;
    bool char_is_num(const char &ch) const;

    // read from file stream when the program is in the give state
    void read_in_starting_state();
    void read_in_identifier();
    void read_in_end_of_identifier();
    void read_in_number();
    void read_in_end_of_number();
    void read_in_comment();
    void read_in_end_of_comment();
    void read_in_found_opening_paranthesis();
    void read_in_big_comment();
    void read_in_star_in_big_comment();
    void read_in_end_of_big_comment();
    void read_in_colon();
    void read_in_colon_equality();
    void read_in_less_then();
    void read_in_less_then_or_equal();
    void read_in_less_then_and_bigger_then();
    void read_in_bigger_then();
    void read_in_bigger_then_or_equal();
    void read_in_end_of_program();
    void read_in_correcting();
    void error(std::string err_msg) const;

    


public:
    Analizer(std::ifstream &file);
    ~Analizer();
    void run_analizer();

};


#endif