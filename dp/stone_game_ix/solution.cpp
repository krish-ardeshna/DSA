#include <bits/stdc++.h>
using namespace std;

// Problem: Stone Game IX
// Link: https://leetcode.com/problems/stone-game-ix/
// Difficulty: Medium
// Pattern: Game Theory + Modular Counting

// ------------------------------------------------------------
// Approach: Mod-3 Bucket Counting + Parity Case Analysis
// ------------------------------------------------------------
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};

int main() {
    Solution obj;
    vector<int> stones = {2, 1};
    cout << obj.stoneGameIX(stones);
    return 0;
}