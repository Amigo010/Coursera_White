//
// Created by stas on 19.10.19.
//
#include <random>
#include <iostream>
#include <iomanip>


void RotateArray(int **a, int n){
    int temp = a[0][0];

    for(int i = 1; i < n; ++i){
        a[i-1][0] = a[i][0];
    }

    for(int i = 1; i < n; ++i){
        a[n-1][i-1] = a[n-1][i];
    }

    for(int i = n-1; i >= 1; --i){
        a[i][n-1] = a[i-1][n-1];
    }

    for(int i = n-1; i >= 2; --i){
        a[0][i] = a[0][i-1];
    }
    a[0][1] = temp;

    if(n - 2 >= 2){
        int **sub_a = new int*[n-2];
        for(int i = 1; i < n-1; ++i){
            sub_a[i-1] = &a[i][1];
        }
        RotateArray(sub_a, n-2);
    }
}

void PrintArray(int **a, int n){
    for(int i = 0; i < n; ++i){
        for(int p = 0; p < n; ++p){
            std::cout << std::setw(2) << a[i][p] << " ";
        }
        std::cout << '\n';
    }
}

void GenerateArray(int **&a, int n){
    a = new int*[n];
    for(int i = 0; i < n; ++i){
        a[i] = new int[n];
        for(int p = 0; p < n; ++p){
            a[i][p] = rand() % 100;
        }
    }
}

int main(){
    int **a;
    int n;
    std::cin >> n;

    GenerateArray(a, n);

    PrintArray(a, n);

    RotateArray(a, n);

    std::cout << "\n\n";

    PrintArray(a, n);
    return 0;
}
