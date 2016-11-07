#include<iostream>
#include<iomanip>
#include<string>
#include"IntegerSet.h"
using namespace std;


IntegerSet::IntegerSet(int s[], int l) {
    for (int i = 0; i < 101; i++)
    set[i] = 0;
    int w;
    for (int i = 0; i < l; i++) {
        if (s[i] >= 0||s[i] <= 101) set[s[i]] = 1;
    }
    for (int i = 0; i < l; i++) {
        if (s[i] < 0||s[i] > 100)
        cout << "Invalid insert attempted!" << endl;
    }
}
IntegerSet IntegerSet::unionOfSets(const IntegerSet& other) {
    IntegerSet c;
    for (int i = 0; i < 101; i++)
    c.set[i] = set[i];
    for (int i = 0; i < 101; i++) {
        if (c.set[i] == 0&&other.set[i] == 0)
            c.set[i] = 0;
        else
            c.set[i] = 1;
    }
    return c;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& other) {
    IntegerSet c;
    for (int i = 0; i < 101; i++)
    c.set[i] = set[i];
    for (int i = 0; i < 101; i++) {
        if (c.set[i] == 1&&other.set[i] == 1)
            c.set[i] = 1;
        else
            c.set[i] = 0;
    }
    return c;
}
void IntegerSet::emptySet() {
    for (int i = 0; i < 101; i++)
    set[i] = 0;
}
void IntegerSet::insertElement(int element) {
    if (!validEntry(element))
        cout << "Invalid insert attempted!" << endl;
    else
        set[element] = 1;
}
void IntegerSet::deleteElement(int element) {
    if (!validEntry(element))
         cout << "Invalid delete attempted!" << endl;
    else set[element] = 0;
}
bool IntegerSet::isEqualTo(const IntegerSet& other) const {
    int count = 0;
    for (int i = 0; i < 101; i++) {
        if (set[i] == other.set[i])
        count++;
    }
    if (count == 101) return true;
    else return false;
}
