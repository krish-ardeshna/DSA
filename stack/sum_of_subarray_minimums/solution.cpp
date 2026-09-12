#include <bits/stdc++.h>
using namespace std;

            // Problem: Sum of Subarray Minimums
// Link: https://leetcode.com/problems/sum-of-subarray-minimums/
// Difficulty: Medium
// Pattern: Monotonic Stack (Previous/Next Smaller Element Contribution)

// ------------------------------------------------------------
// Approach: PSE/NSE via Monotonic Stack + Contribution Counting
// ------------------------------------------------------------
class Solution {
public:
    vector<int> findNSE(const vector<int>& arr, int n) {
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(const vector<int>& arr, int n) {
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        int total = 0;

        vector<int> nse = findNSE(arr, n);
        vector<int> pse = findPSE(arr, n);

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
        }

        return total;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {3, 1, 2, 4};
    cout << obj.sumSubarrayMins(arr);
    return 0;
}