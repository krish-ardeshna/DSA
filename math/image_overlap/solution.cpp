#include <bits/stdc++.h>
using namespace std;

// Problem: Image Overlap
// Link: https://leetcode.com/problems/image-overlap/
// Difficulty: Medium
// Pattern: Hashing (Shift Vector Frequency Counting)

// ------------------------------------------------------------
// Approach: All Ones-Pair Shift Vectors + Frequency Map
// ------------------------------------------------------------
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> ones1, ones2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});

                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> freq;

        int ans = 0;

        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {

                int rowDist = r2 - r1;
                int colDist = c2 - c1;

                freq[{rowDist, colDist}]++;

                ans = max(ans, freq[{rowDist, colDist}]);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    cout << obj.largestOverlap(img1, img2);
    return 0;
}