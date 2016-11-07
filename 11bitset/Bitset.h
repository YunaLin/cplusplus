#include<iostream>
using namespace std;

class Bitset {
    private:
        int n;
        bool a[1100];
    public:
        Bitset();
        void set_size(int x);
        void set(int x);
        void print();
};
Bitset::Bitset() {
    memset(a, 0, sizeof(a));
}
void Bitset::set_size(int x) {
    n = x;
}
void Bitset::set(int x) {
    a[x] = 1;
}
void Bitset::print() {
    for (int i = 0; i < n; i++)
    cout << a[i];
    cout << endl;
}
