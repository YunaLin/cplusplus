#include<iostream>
#include"Set.hpp"
using namespace std;

Set::Set() {
    size = 0;
}
Set::Set(int *m, int s) {
    size = s;
    for (int i = 0; i < size; i++)
    members[i] = m[i];
}
Set::Set(const Set& s) {
    for (int i = 0; i < s.size; i++) {
        members[i] = s.members[i];
    }
    size = s.size;
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
Set Set::operator&(const Set& other) {
    if (other.size == 0) return other;
    int index[100];
    int count = 0;
    Set s = Set(members, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < other.size; j++) {
            if (s.members[i] == other.members[j]) {
            index[count] = i;
            count++;
            }
        }
    }
    int n = 0;
    for (int i = 0; i < s.size; i++) {
        n = 0;
        for (int j = 0; j < count; j++) {
            if (i != index[j])
            n++;
            if (n == count) {
            s.remove(members[i]);
            }
        }
    }
    return s;
}
Set Set::operator|(const Set& other) {
    Set s = Set(members, size);
    for (int j = 0; j < other.size; j++) {
        if (!isInSet(other.members[j])) {
            s.append(other.members[j]);
        }
    }
    return s;
}
Set Set::operator-(const Set& other) {
    Set s = Set(members, size);
    for (int i = 0; i < other.size; i++) {
        if (isInSet(other.members[i])) {
            s.remove(other.members[i]);
        }
    }
    return s;
}
Set Set::operator+(const Set& other) {
    Set s = Set(members, size);
    Set s1 = s - other;
    for (int i = 0; i < other.size; i++) {
        if (!s.isInSet(other.members[i]))
        s1.append(other.members[i]);
    }
    return s1;
}
int * Set::getMembers() {
    return members;
}
int Set::getSize() {
    return size;
}
