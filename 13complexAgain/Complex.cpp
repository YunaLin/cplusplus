#include<iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double re, double im) {
    real = re;
    imaginary = im;
}
Complex Complex::operator + (const Complex &other) {
    Complex c;
    c.real = real + other.real;
    c.imaginary = imaginary + other.imaginary;
    return c;
}
Complex Complex::operator - (const Complex &other) {
    Complex c;
    c.real = real - other.real;
    c.imaginary = imaginary - other.imaginary;
    return c;
}
Complex Complex::operator * (const Complex &other) {
    Complex c;
    c.real = real * other.real - imaginary * other.imaginary;
    c.imaginary = imaginary * other.real + real * other.imaginary;
    return c;
}
Complex Complex::operator / (const Complex &other) {
    Complex c;
    double tmp = other.real*other.real + other.imaginary*other.imaginary;
    c.real = (real * other.real + imaginary * other.imaginary)/tmp;
    c.imaginary = (real*other.imaginary*(-1)+imaginary*other.real)/tmp;
    return c;
}
void Complex::operator += (const Complex &other) {
    real += other.real;
    imaginary += other.imaginary;
}
void Complex::operator -= (const Complex &other) {
    real -= other.real;
    imaginary -= other.imaginary;
}
void Complex::operator *= (const Complex &other) {
    double real1 = real;
    real = real * other.real - imaginary * other.imaginary;
    imaginary = imaginary * other.real + real1 * other.imaginary;
}
void Complex::operator /= (const Complex &other) {
    double real1 = real;
    double tmp = other.real*other.real + other.imaginary*other.imaginary;
    real = (real * other.real + imaginary * other.imaginary)/tmp;
    imaginary = (real1*other.imaginary*(-1)+imaginary*other.real)/tmp;
}
void Complex::SetReal(double re) {
    real = re;
}
void Complex::SetImag(double im) {
    imaginary = im;
}
bool Complex::operator == (const Complex &other) {
    if (other.real == real&&other.imaginary == imaginary)
    return true;
    else return false;
}
bool Complex::operator != (const Complex &other) {
    if (other.real == real&&other.imaginary == imaginary)
    return false;
    else
    return true;
}
ostream & operator << (ostream &os, const Complex &t) {
    os << t.real << "+" << t.imaginary << "i";
    return os;
}
