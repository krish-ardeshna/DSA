#include <bits/stdc++.h>
using namespace std;
// Problem: Sum of Subarray Ranges
// Link: https://leetcode.com/problems/sum-of-subarray-ranges/
// Difficulty: Medium
// Pattern: Monotonic Stack (Max Sum - Min Sum Contribution)
// ------------------------------------------------------------

// ------------------------------------------------------------
// Approach 1: Single-Pass Combined Max-Min via Sentinel Boundary
// ------------------------------------------------------------
class SolutionCombinedPass {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || nums[st.top()] <= nums[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                ans += 1LL * nums[mid] * left * right;
            }

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || nums[st.top()] >= nums[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                ans -= 1LL * nums[mid] * left * right;
            }

            st.push(i);
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Separate Max Sum and Min Sum via NGE/PGE and NSE/PSE
// ------------------------------------------------------------
class SolutionSeparateSums {
public:
    vector<int> findNGE(const vector<int>& arr, int n) {
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nge;
    }

    vector<int> findPGE(const vector<int>& arr, int n) {
        vector<int> pge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            pge[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;

        vector<int> nge = findNGE(arr, n);
        vector<int> pge = findPGE(arr, n);

        for (int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;

            total = total + (right * left * 1LL * arr[i]);
        }

        return total;
    }

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

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;

        vector<int> nse = findNSE(arr, n);
        vector<int> pse = findPSE(arr, n);

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            total = total + (right * left * 1LL * arr[i]);
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    SolutionCombinedPass s1;
    cout << s1.subArrayRanges(nums) << "\n";

    SolutionSeparateSums s2;
    cout << s2.subArrayRanges(nums) << "\n";

    return 0;
}