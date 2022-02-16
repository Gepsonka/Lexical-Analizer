#include "lexical_analizer.h"
#include <fstream>

int main(){
    std::ifstream inputf;
    inputf.open("input.txt");
    Analizer analize(inputf);

    return 0;
}

