#include <bits/stdc++.h>
using namespace std;

// Problem: Design Circular Deque
// Link: https://leetcode.com/problems/design-circular-deque/
// Difficulty: Medium
// Pattern: Queue, Circular Array

// ------------------------------------------------------------
// Approach: Circular Array
// ------------------------------------------------------------

class MyCircularDeque {
public:
    vector<int> dq;
    int front, rear, count, capacity;

    MyCircularDeque(int k) {
        capacity = k;
        dq.resize(k);
        front = 0;
        rear = 0;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;
        dq[front] = value;
        count++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        dq[rear] = value;
        rear = (rear + 1) % capacity;
        count++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        count--;

        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return dq[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return dq[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

int main() {
    MyCircularDeque dq(3);

    cout << boolalpha;
    cout << dq.insertLast(1) << endl;
    cout << dq.insertLast(2) << endl;
    cout << dq.insertFront(3) << endl;
    cout << dq.getRear() << endl;
    cout << dq.getFront() << endl;
    cout << dq.deleteLast() << endl;
    cout << dq.getRear() << endl;

    return 0;
}