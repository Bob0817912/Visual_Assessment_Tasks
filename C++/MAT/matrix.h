#pragma once
#include<iostream>
using namespace std;

class Matrix{
public:
    Matrix(int rows_,int cols_);
    friend void operator >>(istream & in,const Matrix & A);
    friend void operator <<(ostream & out,const Matrix & A);
    friend Matrix operator *(Matrix & A,Matrix & B);
private:
    int rows,cols;
    int **matrix;
};
Matrix :: Matrix(int rows_,int cols_){
    rows = rows_;
    cols = cols_;
    matrix = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0;i < rows;i++){
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
}
void operator >>(istream & in,const Matrix & A){
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < A.cols;j++){
            in >> A.matrix[i][j];
        }
    }
}
void operator <<(ostream & out,const Matrix & A){
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < A.cols;j++){
            out << A.matrix[i][j] << ' ';
        }
        out << endl;
    }
}
Matrix operator *(Matrix & A,Matrix & B){
    Matrix C(A.rows,B.cols);
    for(int i = 0;i < A.rows;i++){
        for(int j = 0;j < B.cols;j++){
            int value = 0;
            for(int k = 0;k < A.cols;k++){
                value += A.matrix[i][k] * B.matrix[k][j];
            }
            C.matrix[i][j] = value;
        }
    }
    return C;
}