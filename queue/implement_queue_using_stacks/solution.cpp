#include <bits/stdc++.h>
using namespace std;

// Problem: Implement Queue using Stacks
// Link: https://leetcode.com/problems/implement-queue-using-stacks/
// Difficulty: Easy
// Pattern: Stack / Design

// ------------------------------------------------------------
// Approach: Two Stacks
// ------------------------------------------------------------

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            transfer();
        }
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }

    int peek() {
        if (outputStack.empty()) {
            transfer();
        }
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);

    cout << q.peek() << "\n";
    cout << q.pop() << "\n";
    cout << boolalpha << q.empty() << "\n";

    return 0;
}