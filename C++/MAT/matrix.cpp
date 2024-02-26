#include<iostream>
#include "matrix.h"

int main() {
    int rows, cols;
    
    std::cin>>"请输入行和列" ;
    std::cin>> rows >> cols;
    Matrix A(rows, cols);
    std::cin >> "请输入矩阵A";
    std::cin >> A;

    std::cin >> rows >> cols;
    Matrix B(rows, cols);
    std::cin >> "请输入矩阵B";
    std::cin >> B;

    std::cout << A * B;

    return 0;
}
