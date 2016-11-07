#include<iostream>
#include "queue.hpp"
using namespace std;
int num = 0;
bool queue::isEmpty(void) {
    if (num == 0) return true;
    else return false;
}
bool queue::isFull(void) {
    if (num == max_size - 1) return true;
    else return false;
}
void queue::push(int n) {
    if (num >= max_size - 1) {
        return;
    } else {
        num++;
        storage[rear] = n;
        rear += 1;
    }
}
void queue::pop(void) {
    if (num != 0) {
        head++;
        num -= 1;
    } else {
        return;
    }
}
int queue::front(void) {
    if (isEmpty()) return 0;
    else return storage[head];
}
int queue::back(void) {
    if (isEmpty()) return 0;
    return storage[rear - 1];
}
void queue::clear(void) {
    num = 0;
    head = rear = 0;
}
