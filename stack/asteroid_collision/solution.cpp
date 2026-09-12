#include <bits/stdc++.h>
using namespace std;

// Problem: Asteroid Collision
// Link: https://leetcode.com/problems/asteroid-collision/
// Difficulty: Medium
// Pattern: Stack Simulation

// ------------------------------------------------------------
// Approach: Stack-Based Collision Simulation
// ------------------------------------------------------------
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < n; i++) {

            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {
                while (!st.empty() &&
                       st.top() > 0 &&
                       st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
                }
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = obj.asteroidCollision(asteroids);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}