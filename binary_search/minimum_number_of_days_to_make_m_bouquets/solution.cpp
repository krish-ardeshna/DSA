#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Number of Days to Make m Bouquets
// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Difficulty: Medium
// Pattern: Binary Search on Answer

// ------------------------------------------------------------
// Approach: Binary Search on Day + Feasibility Check
// ------------------------------------------------------------
class Solution {
public:
    bool possible(int day, const vector<int>& bloomDay, int k, int m) {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) cnt++;
            else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += cnt / k;
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        long long check = 1LL * m * k;
        if (check > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(mid, bloomDay, k, m)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution obj;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << obj.minDays(bloomDay, m, k);
    return 0;
}   