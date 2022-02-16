#include "lexical_analizer.h"
#include <fstream>
#include <iostream>

// g++ -c *.cpp && g++ *.o -o a.out :compiling and linking

int main(){
    std::ifstream inputf;
    inputf.open("input.txt");
    Analizer analize(inputf);
    analize.run_analizer();

    std::cout<<"Task ran successfully"<<std::endl;

    return 0;
}

