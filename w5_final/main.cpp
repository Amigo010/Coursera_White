//
// Created by stas on 18.10.19.
//
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

struct Date{
    int day;
    int month;
    int year;

    std::string ToString(){
        std::stringstream out;
        out << std::setfill('0');
        out << std::setw(4) << year << "-" << std::setw(2) << month << "-" << std::setw(2) << day;
        return out.str();
    }
};

/*
std::istream& operator>>(std::istream& stream, Date& date){
    std::stringstream ss;
    std::string all;
    std::getline(stream, all, ' ');
    ss << all;

    std::string str;
    char c;

    str = "";
    c = (char)ss.get();
    std::getline(ss, str, '-');
    str = (char)c + str;
    try {
        date.year = ToInt(str);
    }catch (std::invalid_argument &e){
        throw std::invalid_argument("Wrong date format: " + all);
    }


    str = "";
    c = (char)ss.get();
    std::getline(ss, str, '-');
    str = (char)c + str;
    std::cout << str << std::endl;
    try {
        date.month = ToInt(str);
    }catch (std::invalid_argument &e){
       // throw std::invalid_argument("Wrong date format: " + all);
    }

    str = "";
    c = (char)ss.get();
    std::getline(ss, str, '-');
    str = (char)c + str;
    try {
        date.day = ToInt(str);
    }catch (std::invalid_argument &e){
        //throw std::invalid_argument("Wrong date format: " + all);
    }

    return stream;
}*/

std::istream& operator>>(std::istream& stream, Date& date){
    stream >> date.year;
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;

    return stream;
}

std::ostream& operator<<(std::ostream& stream, Date& date){
    stream << date.ToString();
    return stream;
}


int main(){
    Date date = {};

    std::stringstream stream("4 5");
    int a, b;
    stream >> a >> b;

    std::cout << a << " " << b;
}
