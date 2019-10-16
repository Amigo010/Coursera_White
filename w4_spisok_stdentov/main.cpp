//
// Created by stas on 14.10.19.
//
#include <iostream>
#include <string>
#include <vector>

struct Student{
    std::string name;
    std::string date;
};

int main(){
    unsigned long N;
    std::cin >> N;

    std::vector<Student> students(N, {"", ""});
    for(auto& student : students){
        std::string fist_name, second_name;
        std::string day, month, year;
        std::cin >> fist_name >> second_name >> day >> month >> year;
        student.name = fist_name + " " + second_name;
        student.date = day + "." + month + "." + year;
    }

    unsigned long M;
    std::cin >> M;
    for(unsigned long i = 0; i < M; ++i){
        std::string request;
        unsigned long n;

        std::cin >> request >> n;
        --n;

        if(request == "name" && n >= 0 && n < N){
            std::cout << students[n].name << '\n';
        }
        else if(request == "date" && n >= 0 && n < N){
            std::cout << students[n].date << '\n';
        }
        else{
            std::cout << "bad request" << '\n';
        }
    }
}

