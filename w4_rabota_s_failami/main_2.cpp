#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string line;
    std::ifstream file_in("input.txt");
    std::ofstream file_out("output.txt");

    while (getline(file_in, line)){
        file_out << line << std::endl;
    }

    return 0;
}
