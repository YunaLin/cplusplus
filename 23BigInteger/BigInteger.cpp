#include<iostream>
#include<string>
#include"BigInteger.h"
using namespace std;

BigInteger::BigInteger() {
    size_ = 0;
}
BigInteger::BigInteger(const string& number) {
    data_ = new int[number.size()];
    size_ = number.size();
    for (int i = size_ - 1; i >= 0; i--)
        data_[i] = number[size_ - 1 - i] - '0';
}
BigInteger::BigInteger(const BigInteger& other) {
    data_ = new int[other.size_];
    size_ = other.size_;
    for (int i = 0; i < size_; i++)
    data_[i] = other.data_[i];
}

BigInteger operator+(const BigInteger& left, const BigInteger& right) {
    BigInteger b;
    int min = (left.size_ < right.size_ ? left.size_:right.size_);
    int max = (left.size_ > right.size_ ? left.size_:right.size_);
    b.data_ = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
    b.data_[i] = 0;
    b.size_ = max;
    for (int i = 0; i < min; i++) {
        b.data_[i] += left.data_[i] + right.data_[i];
        if (b.data_[i] >= 10) {
        b.data_[i] %= 10;
        b.data_[i + 1] += 1;
        }
    }
    if (left.size_ > right.size_) {
        for (int i = min; i < max; i++) {
        b.data_[i] += left.data_[i];
        if (b.data_[i] >= 10) {
            b.data_[i] %= 10;
            b.data_[i + 1] += 1;
        }
        }
    } else {
        for (int i = min; i < max; i++) {
        b.data_[i] += right.data_[i];
        if (b.data_[i] >= 10) {
            b.data_[i] %= 10;
            b.data_[i + 1] += 1;
        }
        }
    }
    if (b.data_[max]!= 0)
        b.size_ += 1;
    return b;
}

BigInteger operator-(const BigInteger& left, const BigInteger& right) {
    int a[100] = {0};
    int b[100] = {0};
    for (int i = 0; i < left.size_; i++)
    a[i] = left.data_[i];
    for (int i = 0; i < right.size_; i++)
    b[i] = right.data_[i];
    int max = left.size_;
    for (int i = 0; i < max - 1; i++) {
        if (a[i] < b[i]) {
        a[i] += 10;
        a[i + 1] -= 1;
        }
        a[i] = a[i] - b[i];
    }
    a[max - 1] -= b[max - 1];
    int len = max;
    int flag = 0;
    for (int i = len - 1; i > 0; i--) {
    if (a[i] != 0) flag = 1;
    if (a[i] == 0&&flag == 0) len -= 1;
    }
    BigInteger bi;
    bi.size_ = len;
    bi.data_ = new int[bi.size_];
    for (int i = 0; i < bi.size_; i++)
    bi.data_[i] = a[i];
    return bi;
}
ostream& operator<<(ostream& os, const BigInteger& Bint) {
    for (int i = Bint.size_ - 1; i >= 0; i--)
    os << Bint.data_[i];
    return os;
}
BigInteger::~BigInteger() {
    delete []data_;
}
