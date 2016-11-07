#include<sstream>
#include<iostream>
#include"Date.h"
using namespace std;

bool Date::isDay() const {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return (day <= 31);
        case 2:
            if ((year%400 == 0)||(year%100 != 0&&year%4 == 0))
                return (day <= 29);
            else return (day <= 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return (day <= 30);
    }
}


void Date::add(int n) {
    while (n--) {
        if (month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month == 12) {
        year += (month+day/31)/13;
        month += day/31;
        day++;
        if (month == 13) month = 1;
        if (day == 32) day = 1;
       } else if (month == 4 || month == 6 ||
         month == 9 || month == 11) {
          year += (month+day/30)/13;
          month += day/30;
          day += 1;
          if (month == 13) month = 1;
          if (day == 31) day = 1;
      } else {
      if ((year%4 == 0 && year%100 != 0)||year%400 == 0) {
          month += day/29;
         day++;
         if (day == 30)
             day = 1;
         } else {
             month += day/28;
             day += 1;
        if (day == 29)
          day = 1;
      }
    }
  }
}
Date::Date() {
    year = 1;
    month = 1;
    day = 1;
}
Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}
Date::Date(const Date& other) {
    year = other.year;
    day = other.day;
    month = other.month;
}
Date::~Date() {
    cout << "Destructor: ";
    cout << "[" << year << "-" << month << "-" << day << "]" << endl;
}
string Date::toString() {
    ostringstream strCat;
    strCat << "[" << year << "-" << month << "-" << day << "]";
    return strCat.str();
}
void Date::setDay(int d) {
    day = d;
}
Date& Date::operator++() {
    (*this).add(1);
    return *this;
}
Date Date::operator++(int n) {
    Date d = *this;
    (*this).add(1);
    return d;
}
Date Date::after(int n) {
    Date d = *this;
    d.add(n);
    return d;
}
bool Date::operator<(const Date& other) {
    if (year < other.year) {
        return true;
    } else if (year == other.year) {
        if (month < other.month) {
            return true;
        } else if (month == other.month) {
            if (day < other.day)
            return true;
        }
    }
    return false;
}
bool Date::operator>(const Date& other) {
    if (year > other.year) {
        return true;
    } else if (year == other.year) {
        if (month > other.month) {
            return true;
        } else if (month == other.month) {
            if (day > other.day)
            return true;
        }
    }
    return false;
}
bool Date::operator==(const Date& other) {
    if (year == other.year)
        if (month == other.month)
            if (day == other.day)
            return true;
    return false;
}
bool Date::operator!=(const Date& other) {
    if (year == other.year)
        if (month == other.month)
            if (day == other.day)
            return false;
    return true;
}
int& Date::operator[](int n) {
    if (n == 0) return year;
    if (n == 1) return month;
    if (n == 2) return day;
}
ostream& operator<<(ostream& os, const Date& other) {
    os << "[" << other.year << "-" << other.month << "-" << other.day << "]"
    << endl;
    return os;
}
istream& operator>>(istream& is, Date& other) {
    is >> other.year >> other.month >> other.day;
    return is;
}
void Date::operator=(const Date& other) {
    year = other.year;
    month = other.month;
    day = other.day;
}
bool Date::isValid() const {
    if (year <= 0) return false;
    else if (month <= 0||month > 12) return false;
    else if (day > 31||day <= 0) {
        return false;
    } else {
        this->isDay();
        }
}
