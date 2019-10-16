//
// Created by stas on 12.10.19.
//
#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string line;
    std::ifstream file_in("input.txt");

    while (getline(file_in, line)){
        std::cout << line << std::endl;
    }

    return 0;
}
