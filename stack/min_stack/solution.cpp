#include <bits/stdc++.h>
using namespace std;

// Problem: Min Stack
// Link: https://leetcode.com/problems/min-stack/
// Difficulty: Medium
// Pattern: Stack / Design

// ------------------------------------------------------------
// Approach 1: Stack of Pairs
// ------------------------------------------------------------

class MinStackPairs {
public:
    stack<pair<int, int>> st;

    MinStackPairs() {
    }

    void push(int val) {
        if (!st.empty()) {
            st.push({val, min(val, st.top().second)});
        }
        else {
            st.push({val, val});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

// ------------------------------------------------------------
// Approach 2: Two Stacks
// ------------------------------------------------------------

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
    }

    void push(int value) {
        st.push(value);

        if (minSt.empty()) {
            minSt.push(value);
        }
        else {
            minSt.push(min(value, minSt.top()));
        }
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack obj;

    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    cout << obj.getMin() << "\n";

    obj.pop();

    cout << obj.top() << "\n";
    cout << obj.getMin() << "\n";

    return 0;
}