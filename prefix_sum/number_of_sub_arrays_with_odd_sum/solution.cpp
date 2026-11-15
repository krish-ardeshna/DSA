#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Sub-arrays With Odd Sum
// Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
// Difficulty: Medium
// Pattern: Prefix Sum Parity Counting / DP on Subarrays Ending at Each Index

const int MOD = 1e9 + 7;

// ------------------------------------------------------------
// Approach 1: Brute Force (Running Sum From Every Start)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int parity = 0;

            for (int j = i; j < n; j++) {
                parity ^= (arr[j] & 1);

                if (parity == 1)
                    ans++;
            }
        }

        return ans % MOD;
    }
};

// ------------------------------------------------------------
// Approach 2: Prefix Sum Parity Counting
// ------------------------------------------------------------
class SolutionPrefixParity {
public:
    int numOfSubarrays(vector<int>& arr) {
        // even / odd = how many prefixes so far have an even / odd sum
        // (the empty prefix has sum 0, which is even)
        long long even = 1, odd = 0, ans = 0;
        int parity = 0;

        for (int x : arr) {
            parity ^= (x & 1);

            if (parity == 1) {
                // odd prefix - even prefix = odd subarray
                ans = (ans + even) % MOD;
                odd++;
            } else {
                // even prefix - odd prefix = odd subarray
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: DP (Count Subarrays Ending at Each Index by Parity)
// ------------------------------------------------------------
class SolutionDP {
public:
    int numOfSubarrays(vector<int>& arr) {
        // oddEnd / evenEnd = number of subarrays ending at the current index
        // with an odd / even sum
        long long oddEnd = 0, evenEnd = 0, ans = 0;

        for (int x : arr) {
            long long newOdd, newEven;

            if (x & 1) {
                // odd number flips the parity, and the subarray [x] itself is odd
                newOdd = evenEnd + 1;
                newEven = oddEnd;
            } else {
                // even number keeps the parity, and the subarray [x] itself is even
                newOdd = oddEnd;
                newEven = evenEnd + 1;
            }

            oddEnd = newOdd;
            evenEnd = newEven;

            ans = (ans + oddEnd) % MOD;
        }

        return ans;
    }
};

int main() {
    vector<int> a1 = {1, 3, 5};
    vector<int> a2 = {2, 4, 6};
    vector<int> a3 = {1, 2, 3, 4, 5, 6, 7};

    SolutionBruteForce s1;
    cout << s1.numOfSubarrays(a1) << " "
         << s1.numOfSubarrays(a2) << " "
         << s1.numOfSubarrays(a3) << "\n";

    SolutionPrefixParity s2;
    cout << s2.numOfSubarrays(a1) << " "
         << s2.numOfSubarrays(a2) << " "
         << s2.numOfSubarrays(a3) << "\n";

    SolutionDP s3;
    cout << s3.numOfSubarrays(a1) << " "
         << s3.numOfSubarrays(a2) << " "
         << s3.numOfSubarrays(a3) << "\n";

    return 0;
}