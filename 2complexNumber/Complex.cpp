#include<iostream>
#include"Complex.h"
using namespace std;

Complex::Complex(double real, double imaginary) {
    setComplexNumber(real, imaginary);
}
Complex::Complex() {
    realPart = 0;
    imaginaryPart = 0;
}
Complex Complex::add(const Complex &right) {
    realPart = realPart + right.realPart;
    imaginaryPart = imaginaryPart + right.imaginaryPart;
    return *this;
}
Complex Complex::subtract(const Complex &right) {
    realPart = realPart - right.realPart;
    imaginaryPart = imaginaryPart - right.imaginaryPart;
    return *this;
}
void Complex::printComplex() {
    cout << '(' << realPart << ", " << imaginaryPart << ')';
}
void Complex::setComplexNumber(double rp, double ip) {
    realPart = rp;
    imaginaryPart = ip;
}
