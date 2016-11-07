#include<iostream>

#include"array.hpp"
using namespace std;
array::array(size_t size) {
    _data = new int[_size + 20];
    _size = size;
}
array::~array() {
    delete [] _data;
}
unsigned int array::max_size(void) {
    return _size;
}
int& array::at(const int& i) {
    return _data[i];
}
int& array::front() {
    return _data[0];
}
int& array::back() {
    return _data[_size - 1];
}
int* array::data() {
    return _data;
}
void array::fill(const int& value) {
    for (int i = 0; i < _size; i++)
    _data[i] = value;
}
void array::resize(int newSize) {
    _size = newSize;
}
void array::sort(int from, int to) {
    int t;
    for (int i = from; i < to; i++) {
        for (int j = i; j < to; j++) {
            if (_data[i] > _data[j]) {
                t = _data[i];
                _data[i] = _data[j];
                _data[j] = t;
            }
        }
    }
}
