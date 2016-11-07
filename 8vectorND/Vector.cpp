#include<iostream>
#include<string>
#include "Vector.h"
using namespace std;

Vector::Vector(string s, int dim, int n[]) {
    param = new int[dim + 1];
    cout << "construct a vector called " << s << "." << endl;
    name = s;
    dimension = dim;
    for (int i = 0; i < dim; i++)
    param[i] = n[i];
}

Vector::Vector(const Vector &otherVec) {
    param = new int[otherVec.dimension + 1];
    cout << "copy a vector called " << otherVec.name << "." << endl;
    name = otherVec.name;
    dimension = otherVec.dimension;
    for (int i = 0; i < dimension; i++)
    param[i] = otherVec.param[i];
}
Vector::~Vector() {
    cout << "release memory from a vector called " << name << "." << endl;
    delete [] param;
}

void Vector::isEqual(const Vector &v) {
    int flag = 0;
    for (int i = 0; i < v.dimension; i++) {
        if (param[i] != v.param[i]) {
        flag = 1;
        break;
        }
    }
    if (name == v.name) {
        if (dimension == v.dimension&&flag == 0)
            cout << "same name, same value." << endl;
        else
            cout << "same name, different value." << endl;
    } else {
        if (dimension == v.dimension&&flag == 0)
            cout << "different name, same value." << endl;
        else
            cout << "different name, different value." << endl;
    }
}
void Vector::setName(string str) {
    name = str;
}
void Vector::print() {
    cout << name << "(";
    for (int i = 0; i < dimension - 1; i++)
    cout << param[i] << ", ";
    cout << param[dimension - 1] << ")" << endl;
}
