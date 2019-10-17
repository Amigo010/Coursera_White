//
// Created by stas on 12.10.19.
//
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>



int main(){
   std::ifstream file_in("input.txt");

    int n, m;
    file_in >> n >> m;
    file_in.ignore(1);

    std::string line;
    for(int i = 0; i < n; ++i){
        for(int p = 0; p < m; ++p){
            getline(file_in, line, p+1 != m ? ',' : '\n');
            std::cout << std::setw(10);

            std::cout << line;
            if(p + 1 != m){
                std::cout << ' ';
            }
        }

        if(i+1 != n){
            std::cout << '\n';
        }
    }

    return 0;
}