#include<iostream>
#include"PersonalAccount.h"
using namespace std;
PersonalAccount::PersonalAccount() {
    balance = 0;
}
void PersonalAccount::add(int value) {
    balance += value;
}
void PersonalAccount::subtract(int value) {
    int t;
    t = balance - value;
    if (t >= 0) balance = t;
    else cout << "insufficient balance.." << endl;
}
void PersonalAccount::getBalance() {
    cout << "The Balance is: " << balance << endl;
}
