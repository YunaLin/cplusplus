#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include"Point.h"
using namespace std;
Point::Point() {
    x = y = 0.0;
}
Point::Point(double a, double b) {
    x = a;
    y = b;
}

void Point::reset(const double &a, const double &b) {
    x = a;
    y = b;
}
string Point::display() {
  ostringstream strCat;
  strCat << "(" << x << ", " << y << ")";
  return strCat.str();
}
double dist_PP(const Point& p1, const Point& p2) {
    double d;
    d = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    return d;
}
