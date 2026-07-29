#include <bits/stdc++.h>
using namespace std;

// Problem: Design Circular Queue
// Link: https://leetcode.com/problems/design-circular-queue/
// Difficulty: Medium
// Pattern: Queue, Circular Array

// ------------------------------------------------------------
// Approach: Circular Array
// ------------------------------------------------------------

class MyCircularQueue {
public:
    vector<int> q;
    int front, rear, count, capacity;

    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = 0;
        rear = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        q[rear] = value;
        rear = (rear + 1) % capacity;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return q[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return q[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

int main() {
    cout << "This is a design problem. Test cases are handled by LeetCode's driver code." << endl;
    return 0;
}