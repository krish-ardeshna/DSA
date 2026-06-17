#include <bits/stdc++.h>
using namespace std;

// Problem: Implement Stack using Queues
// Link: https://leetcode.com/problems/implement-stack-using-queues/
// Difficulty: Easy
// Pattern: Queue / Design

// ------------------------------------------------------------
// Approach: Single Queue Rotation
// ------------------------------------------------------------

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        q.push(x);
        int sz = q.size();

        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(1);
    st.push(2);

    cout << st.top() << "\n";
    cout << st.pop() << "\n";
    cout << boolalpha << st.empty() << "\n";

    return 0;
}