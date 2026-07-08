#include <bits/stdc++.h>
using namespace std;

// Problem: Design Browser History
// Link: https://leetcode.com/problems/design-browser-history/
// Difficulty: Medium
// Pattern: Design

// ------------------------------------------------------------
// Approach: Vector with Current Pointer
// ------------------------------------------------------------

class BrowserHistory {
public:
    vector<string> history;
    int curr;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }

    void visit(string url) {
        history.resize(curr + 1);
        history.push_back(url);

        curr++;
    }

    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = min((int)history.size() - 1, curr + steps);
        return history[curr];
    }
};

int main() {
    BrowserHistory browser("leetcode.com");

    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << browser.back(1) << "\n";
    cout << browser.back(1) << "\n";
    cout << browser.forward(1) << "\n";

    browser.visit("linkedin.com");

    cout << browser.forward(2) << "\n";
    cout << browser.back(2) << "\n";
    cout << browser.back(7) << "\n";

    return 0;
}