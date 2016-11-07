#include<iostream>
#include<cmath>
#include<cstdlib>
#include"Vector.h"
using namespace std;

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(int an, int bn) {
    x = an;
    y = bn;
}
Vector::Vector(const Vector &otherVec) {
    x = otherVec.x;
    y = otherVec.y;
}
Vector Vector::add(Vector av) {
    Vector c(x, y);
    c.x += av.x;
    c.y += av.y;
    return c;
}
Vector Vector::sub(Vector av) {
    Vector c(x, y);
    c.x -= av.x;
    c.y -= av.y;
    return c;
}
Vector Vector::inverse() {
    x = x*(-1);
    y = y*(-1);
    return *this;
}
int Vector::dot_product(Vector av) {
    int result;
    result = abs(x*av.x + y*av.y);
    return result;
}
int Vector::cross_product(Vector av) {
    int result;
    result = abs(x*av.y - y*av.x);
    return result;
}
void Vector::print() {
    cout << '(' << x << ", " << y << ')' << endl;
}
