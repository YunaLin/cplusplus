#include<iostream>
#include<string>
#include"Matrix.h"
using namespace std;

Matrix::Matrix() {
    cout << "construct an uninnitialised matrix." << endl;
    name = "";
    width = 0;
    height = 0;
}
Matrix::Matrix(string n, int h, int w, int **p) {
    cout << "construct a matrix called " << n << "." << endl;
    name = n;
    width = w;
    height = h;
    param = new int*[height];
    for (int i = 0; i < height; i++)
        param[i] = new int[width];
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
        param[i][j] = p[i][j];
}
Matrix::Matrix(const Matrix& other) {
    cout << "copy construct a matrix called " << other.name << "." << endl;
    name = other.name;
    width = other.width;
    height = other.height;
    param = new int*[height];
    for (int i = 0; i < height; i++)
        param[i] = new int[width];
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
        param[i][j] = other.param[i][j];
}

Matrix::~Matrix() {
    cout << "release memory from a matrix called " << name << "." << endl;
    for (int i = 0; i < height; i++)
        delete []param[i];
    delete []param;
}
void Matrix::setName(string n) {
    name = n;
}
void Matrix::print() {
    cout << name << " = [" << endl;
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j++)
            cout << param[i][j] << ", ";
        cout << param[i][width - 1] << endl;
    }
    cout << "]" << endl;
}
