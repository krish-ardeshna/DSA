#include <bits/stdc++.h>
using namespace std;
// Problem: Maximum Gap Between Stations
// Link: https://leetcode.com/problems/maximum-gap-between-stations/
// Difficulty: Medium (contest problem)  
// Pattern: String - Two Pointer (Leftmost/Rightmost Match Tracking)
// ------------------------------------------------------------
// Approach: Precompute Leftmost and Rightmost Match Positions
// ------------------------------------------------------------
class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        vector<int> left(n);
        vector<int> right(m);

        int j = 0;

        for (int i = 0; i < n; i++) {
            while (station[j] != skill[i]) j++;

            left[i] = j;
            j++;
        }

        j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            while (station[j] != skill[i]) j--;

            right[i] = j;
            j--;
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            ans = max(ans, right[i] - left[i - 1]);
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string skill = "abc";
    string station = "xaxbxcx";
    cout << obj.maximumGap(skill, station);
    return 0;
}