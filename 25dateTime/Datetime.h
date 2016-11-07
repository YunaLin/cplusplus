#include<iostream>
#include<string>
#include<sstream>
#include"Date.h"
#include"Time.h"
using namespace std;

class Datetime:public Date, public Time {
  public:
  Datetime(int y, int m, int d, int hr, int min, int sec);
  Datetime(const Date& d, const Time& t);
  ~Datetime();
  string toString();
  Datetime after(int seconds);
  bool operator<(const Datetime& dt);
  bool operator>(const Datetime& dt);
  Datetime& operator=(const Datetime& dt);
  bool operator==(const Datetime& dt);
  bool operator!=(const Datetime& dt);
  Datetime& operator++();
  Datetime operator++(int temp);
};
