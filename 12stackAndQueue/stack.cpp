#include<iostream>
#include<iomanip>
#include "stack.hpp"
using namespace std;
bool stack::isEmpty(void) {
  return top == -1;
}

bool stack::isFull(void) {
    return top == max_size - 1;
}

void stack::push(int n) {
    if (top < max_size - 1) {
    storage[++top] = n;
    }
}
void stack::pop(void) {
    if (top >= 0)
    --top;
}

int stack::peek(void) {
    return storage[top];
}
void stack::clear(void) {
    top = -1;
}
