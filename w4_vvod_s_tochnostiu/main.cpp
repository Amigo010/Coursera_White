//
// Created by stas on 12.10.19.
//
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main(){
    std::ifstream file_in("input.txt");

    double num;

    std::cout << std::fixed << std::setprecision(3);
    while(file_in >> num){
        std::cout << num << std::endl;
    }

    return 0;
}

