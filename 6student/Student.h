#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Student {
    public:
    Student(int, const char* = "No Name", int = 0);
    Student();
    void set(int, const char*, int);
    void print();
    private:
    int id;
    char name[50];
    int age;
};

Student::Student() {
    id = 0;
    strncpy(name, "No Name", 8);
    age = 0;
}
Student::Student(int n, const char* nm, int a) {
    id = n;
    strncpy(name, nm, strlen(nm) + 1);
    age = a;
}
void Student::set(int n, const char *nm, int a) {
    id = n;
    strncpy(name, nm, strlen(nm) + 1);
    age = a;
}
void Student::print() {
    cout << name << " (" << id << ")" << " is " << age << " years old." << endl;
}
