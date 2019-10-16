//
// Created by stas on 16.10.19.
//

#include <iostream>
#include <cmath>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        numerator = new_numerator;
        denominator = new_denominator;

        Cut();
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    Rational operator+(const Rational& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Rational(new_num, new_den);
    }

    Rational operator-(const Rational& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Rational(new_num, new_den);
    }

    Rational operator*(const Rational& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Rational(new_num, new_den);
    }

    Rational operator/(const Rational& other) const {
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return Rational(new_num, new_den);
    }

private:

    void Cut(){
        if(denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }else if(numerator == 0){
            denominator = 1;
        }

        int d = HOD(std::abs(numerator), denominator);
        numerator /= d;
        denominator /= d;
    }

    int HOD(int a, int b){
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        return a + b;
    }

    int numerator;
    int denominator;
};

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}