#ifndef EXCHANGE_H__
#define EXCHANGE_H__
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string change1(char *ch) {  // 将char数组转换为string
    string str = ch;
    return str;
}
void change2(string str, char *a) {   // 将string转换为char数组
    strncpy(a, str.c_str(), str.size());
}
#endif
