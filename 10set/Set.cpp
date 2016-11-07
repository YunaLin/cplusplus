#include<iostream>
#include<cstdlib>
#include<iomanip>
#include "Set.hpp"
using namespace std;
Set::Set() {
    size = 0;
}
Set::Set(int *m, int s) {
    size = s;
    for (int i = 0; i < size; i++)
    members[i] = m[i];
}
bool Set::isInSet(int e) {
    int flag = 0;
    for (int i = 0; i < size; i++)
        if (members[i] == e) {
            flag = 1;
            break;
        }
    if (flag == 1) return true;
    else return false;
}

bool Set::append(int e) {
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (members[i] == e) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        members[size] = e;
        size += 1;
        return true;
    } else {
        return false;
    }
}
bool Set::remove(int e) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (members[i] == members[j]) {
                for (int k = j; k < size - 1; k++)
                members[k] = members[k + 1];
                size -= 1;
            }
        }
    }
    int count = size;
    int con = size;
    int i;
    for (i = 0; i < size; i++) {
        if (members[i] == e) {
            for (int j = i; j < size - 1; j++)
            members[j] = members[j + 1];
            size -= 1;
            count = size;
            i -= 1;
        }
    }
    if (count == con) return false;
    else return true;
}
bool Set::isEmptySet() {
    if (size == 0) return true;
    else return false;
}
int* Set::getMembers() {
    return members;
}
int Set::getSize() {
    return size;
}
