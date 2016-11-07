#include"Datetime.h"
#include<sstream>
using namespace std;


Datetime::Datetime(int y, int m, int d, int hr, int min, int sec):\
Date(y, m, d), Time(hr, min, sec) {}
Datetime::Datetime(const Date& d, const Time& t):Date(d), Time(t) {}
string Datetime::toString() {
  Date::toString();
  Time::toString();
  string result;
  result = Date::toString();
  result += " ";
  result += Time::toString();
  return result;
}
Datetime::~Datetime() {
  cout << "Destructor: " << this->toString() << endl;
}
bool Datetime::operator<(const Datetime& dt) {
  if (getYear() < dt.getYear()) return true;
  else if (getYear() == dt.getYear()) {
    if (getMonth() < dt.getMonth()) return true;
    else if (getMonth() == dt.getMonth()) {
      if (getDay() < dt.getDay()) return true;
      else if (getDay() == dt.getDay()) {
        if (getHour() < dt.getHour()) return true;
        else if (getHour() == dt.getHour()) {
          if (getMinute() < dt.getMinute()) return true;
          else if (getMinute() == dt.getMinute()) {
            if (getSecond() < dt.getSecond()) return true;
            else return false;
          } else {
            return false;
          }
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }
}
bool Datetime::operator>(const Datetime& dt) {
  if (getYear() > dt.getYear()) return true;
  else if (getYear() == dt.getYear()) {
    if (getMonth() > dt.getMonth()) return true;
    else if (getMonth() == dt.getMonth()) {
      if (getDay() > dt.getDay()) return true;
      else if (getDay() == dt.getDay()) {
        if (getHour() > dt.getHour()) return true;
        else if (getHour() == dt.getHour()) {
          if (getMinute() > dt.getMinute()) return true;
          else if (getMinute() == dt.getMinute()) {
            if (getSecond() > dt.getSecond()) return true;
            else return false;
          } else {
            return false;
          }
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }
}
bool Datetime::operator==(const Datetime& dt) {
  if (getYear() == dt.getYear())
  if (getMonth() == dt.getMonth())
  if (getDay() == dt.getDay())
  if (getHour() == dt.getHour())
  if (getMinute() == dt.getMinute())
  if (getSecond() == dt.getSecond())
  return true;
  return false;
}
bool Datetime::operator!=(const Datetime& dt) {
  if (getYear() == dt.getYear())
  if (getMonth() == dt.getMonth())
  if (getDay() == dt.getDay())
  if (getHour() == dt.getHour())
  if (getMinute() == dt.getMinute())
  if (getSecond() == dt.getSecond())
  return false;
  return true;
}
Datetime& Datetime::operator=(const Datetime& dt) {
  setYear(dt.getYear());
  setMonth(dt.getMonth());
  setDay(dt.getDay());
  setHour(dt.getHour());
  setMinute(dt.getMinute());
  setSecond(dt.getSecond());
  return *this;
}
Datetime& Datetime::operator++() {
  setSecond(getSecond() + 1);
  if (getSecond() >= 60) {
    setMinute(getMinute() + getSecond()/60);
    setSecond(getSecond()%60);
    if (getMinute() >= 60) {
      setHour(getMinute()/60 + getHour());
      setMinute(getMinute()%60);
      if (getHour() >= 12) {
      setDay(getDay() + getHour()/24);
      setHour(getHour()%24);
      }
    }
  }
  if (!daysOfMonth()) {
    switch (getMonth()) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
      setMonth(getDay()/31);
      setDay(getDay()%31);
      if (getMonth() > 12) {
        setYear(getMonth()/12);
        setMonth(getMonth()%12);
      }
      case 4:
      case 6:
      case 9:
      case 11:
      setMonth(getDay()/30);
      setDay(getDay()%30);
      if (getMonth() > 12) {
        setYear(getMonth()/12);
        setMonth(getMonth()%12);
      }
      case 2:
      if ((getYear()%4 == 0&&getYear()%100 != 0)||getYear()%400 == 0) {
        setMonth(getDay()/29);
        setDay(getDay()%29);
        if (getMonth() > 12) {
          setYear(getMonth()/12);
          setMonth(getMonth()%12);
        }
      } else {
        setMonth(getDay()/28);
        setDay(getDay()%28);
        if (getMonth() > 12) {
          setYear(getMonth()/12);
          setMonth(getMonth()%12);
        }
      }
    }
  }
  return *this;
}
Datetime Datetime::operator++(int temp) {
  Datetime dt = *this;
  ++(*this);
  return dt;
}
Datetime Datetime::after(int seconds) {
  Datetime dt = Datetime(getYear(), getMonth(), getDay(), getHour(), \
  getMinute(), getSecond());
  dt.setSecond(dt.getSecond() + seconds);
  if (dt.getSecond() >= 60) {
    dt.setMinute(dt.getMinute() + dt.getSecond()/60);
    dt.setSecond(dt.getSecond()%60);
    if (dt.getMinute() >= 60) {
      dt.setHour(dt.getMinute()/60 + dt.getHour());
      dt.setMinute(dt.getMinute()%60);
      if (dt.getHour() >= 24) {
      dt.setDay(dt.getDay() + dt.getHour()/24);
      dt.setHour(dt.getHour()%24);
      }
    }
  }
    switch (dt.getMonth()) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
      if (dt.getDay() > 31) {
      dt.setMonth(dt.getMonth() + dt.getDay()/31);
      dt.setDay(dt.getDay()%31);
      if (dt.getMonth() > 12) {
        dt.setYear(dt.getYear() + dt.getMonth()/12);
        dt.setMonth(dt.getMonth()%12);
      }
      }
      case 4:
      case 6:
      case 9:
      case 11:
      if (dt.getDay() > 30) {
      dt.setMonth(dt.getMonth() + dt.getDay()/30);
      dt.setDay(dt.getDay()%30);
      if (dt.getMonth() > 12) {
        dt.setYear(dt.getYear() + dt.getMonth()/12);
        dt.setMonth(dt.getMonth()%12);
      }
      }
      case 2:
      if ((dt.getYear()%4 == 0&&dt.getYear()%100 != 0)||dt.getYear()%400 == 0) {
        if (dt.getDay() > 29) {
        dt.setMonth(dt.getMonth() + dt.getDay()/29);
        dt.setDay(dt.getDay()%29);
        if (dt.getMonth() > 12) {
          dt.setYear(dt.getYear() + dt.getMonth()/12);
          dt.setMonth(dt.getMonth()%12);
        }
        }
      } else {
        if (dt.getDay() > 28) {
        dt.setMonth(dt.getMonth() + dt.getDay()/28);
        dt.setDay(dt.getDay()%28);
        if (dt.getMonth() > 12) {
          dt.setYear(dt.getYear() + dt.getMonth()/12);
          dt.setMonth(dt.getMonth()%12);
        }
        }
      }
    }
  return dt;
}
