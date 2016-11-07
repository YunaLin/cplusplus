#include<iostream>
using namespace std;
class Complex {
    public:
        Complex(double = 0.0, double = 0.0);
        void SetReal(double re);
        void SetImag(double im);
        friend ostream & operator << (ostream &os, const Complex &t);
        Complex operator + (const Complex &other);
        Complex operator - (const Complex &other);
        Complex operator * (const Complex &other);
        Complex operator / (const Complex &other);
        bool operator == (const Complex &other);
        bool operator != (const Complex &other);
        void operator += (const Complex &other);
        void operator -= (const Complex &other);
        void operator *= (const Complex &other);
        void operator /= (const Complex &other);
    private:
        double real;
        double imaginary;
};
