#include"Line.h"
#include"Point.h"
#include<cmath>
#include<sstream>
#include<iostream>
using namespace std;
Line::Line() {
    a = 0.0;
    b = 0.0;
    c = 0.0;
}
Line::Line(double x, double y, double z) {
    a = x;
    b = y;
    c = z;
}

void Line::reset(const double &x, const double &y, const double &z) {
    a = x;
    b = y;
    c = z;
}
double dist_LP(const Line& l, const Point& p) {
    double d1, d2, d;
    d1 = l.a * p.x + l.b * p.y + l.c;
    d2 = sqrt(l.a * l.a + l.b * l.b);
    d = fabs(d1/d2);
    return d;
}
double dist_LL(const Line& l1, const Line& l2) {
    if (l1.a * l2.b == l1.b * l2.a) {
    double t1, t2, d1, d2, t3, d;
    if (fabs(l1.a) >= fabs(l2.a)) {
    t1 = l1.c;
    t2 = l1.a/l2.a;
    t1 = t1/t2;
    d1 = fabs(t1 - l2.c);
    d2 = sqrt(l2.a * l2.a + l2.b * l2.b);
    d = d1/d2;
    return d;
    } else if (fabs(l1.a) < fabs(l2.a)) {
    t1 = l2.c;
    t2 = l2.a/l1.a;
    t1 = t1/t2;
    d1 = fabs(t1 - l2.c);
    d2 = sqrt(l2.a * l2.a + l2.b * l2.b);
    d = d1/d2;
    }
    } else {
    return -1;
    }
}
string Line::display() {
  ostringstream strCat;
  if (a != 0&&b != 0) {
  if (b > 0&&c > 0)
  strCat << a << "x+" << b << "y+" << c << "=0";
  else if (b < 0&&c > 0)
  strCat << a << "x" << b << "y+" << c << "=0";
  else if (b < 0&&c < 0)
  strCat << a << "x" << b << "y" << c << "=0";
  else if (b > 0&&c < 0)
  strCat << a << "x+" << b << "y" << c << "=0";
  else if (b > 0&&c == 0)
  strCat << a << "x+" << b << "y=0";
  else if (b < 0&&c == 0)
  strCat << a << "x" << b << "y=0";
  } else if (a == 0&&b != 0) {
  if (c >= 0) strCat << b << "y+" << c << "=0";
  else strCat << b << "y" << c << "=0";
  } else if (a != 0&&b == 0) {
  if (c >= 0) strCat << a << "a+" << c << "=0";
  else strCat << a << "a" << c << "=0";
  } else {
  strCat << c << "=0";
  }
  return strCat.str();
}
