#include <bits/stdc++.h>
using namespace std;

// Problem: Destroying Asteroids
// Link: https://leetcode.com/problems/destroying-asteroids/
// Difficulty: Medium
// Pattern: Greedy

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;

        for (int asteroid : asteroids) {
            if (currMass < asteroid) {
                return false;
            }
            currMass += asteroid;
        }
        return true;
    }
};

int main() {
    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};

    Solution s;

    cout << s.asteroidsDestroyed(mass, asteroids) << "\n";

    return 0;
}