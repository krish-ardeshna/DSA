#include <bits/stdc++.h>
using namespace std;

// Problem: Cinema Seat Allocation
// Link: https://leetcode.com/problems/cinema-seat-allocation/
// Difficulty: Medium
// Pattern: Bit Manipulation (Bitmask per Row)

// ------------------------------------------------------------
// Approach: Row Bitmask + Fixed 3-Window Check
// ------------------------------------------------------------
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;
        // Build a bitmask for each row containing reservations.
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Only seats 2 to 9 matter.
            if (col >= 2 && col <= 9) {
                rows[row] |= (1 << col);
            }
        }
        long long ans = 2LL * (n - rows.size());
        for (auto &[row, mask] : rows) {
            // 2,3,4,5
            bool left = (mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5))) == 0;
            // 4,5,6,7
            bool middle = (mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) == 0;
            // 6,7,8,9
            bool right = (mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))) == 0;
            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int n = 3;
    vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    cout << obj.maxNumberOfFamilies(n, reservedSeats);
    return 0;
}