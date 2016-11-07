#ifndef COMPLEX_H__
#define COMPLEX_H__
class Complex {
    public:
    Complex(double real, double imaginary);
    Complex();
    Complex add(const Complex &right);
    Complex subtract(const Complex& right);
    void printComplex();
    void setComplexNumber(double rp, double ip);
    private:
    double realPart;
    double imaginaryPart;
};

#endif
