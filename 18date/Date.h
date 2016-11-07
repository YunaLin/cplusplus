#include<iostream>
#include<string>
using namespace std;
class Date {
    public:
    Date(int y, int m, int d);
    Date();
    ~Date();
    Date(const Date& other);
    string toString();
    void setDay(int d);
    bool isValid() const;
    bool isDay() const;
    Date after(int n);
    void add(int n);
    bool operator<(const Date& other);
    bool operator>(const Date& other);
    void operator=(const Date& other);
    bool operator==(const Date& other);
    bool operator!=(const Date& other);
    int& operator[](int n);
    Date& operator++();
    Date operator++(int n);
    friend ostream& operator<<(ostream& os, const Date& other);
    friend istream& operator>>(istream& is, Date& other);
    private:
    int year;
    int month;
    int day;
};
