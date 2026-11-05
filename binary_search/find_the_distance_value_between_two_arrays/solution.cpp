#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Distance Value Between Two Arrays
// Link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Difficulty: Easy
// Pattern: Brute Force + Sorting & Binary Search (Nearest Value)

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        for (int x : arr1) {
            bool valid = true;

            for (int y : arr2) {
                if (abs(x - y) <= d) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans++;
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Sort + Binary Search
// ------------------------------------------------------------
class SolutionBinarySearch {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;

        for (int x : arr1) {
            // first value in arr2 that is >= x
            auto it = lower_bound(arr2.begin(), arr2.end(), x);

            bool valid = true;

            // closest value on the right (>= x)
            if (it != arr2.end() && *it - x <= d)
                valid = false;

            // closest value on the left (< x)
            if (it != arr2.begin() && x - *prev(it) <= d)
                valid = false;

            if (valid)
                ans++;
        }

        return ans;
    }
};

int main() {
    vector<int> a1 = {4, 5, 8}, b1 = {10, 9, 1, 8};
    vector<int> a2 = {1, 4, 2, 3}, b2 = {-4, -3, 6, 10, 20, 30};
    vector<int> a3 = {2, 1, 100, 3}, b3 = {-5, -2, 10, -3, 7};

    SolutionBruteForce s1;
    cout << s1.findTheDistanceValue(a1, b1, 2) << " "
         << s1.findTheDistanceValue(a2, b2, 3) << " "
         << s1.findTheDistanceValue(a3, b3, 6) << "\n";

    SolutionBinarySearch s2;
    cout << s2.findTheDistanceValue(a1, b1, 2) << " "
         << s2.findTheDistanceValue(a2, b2, 3) << " "
         << s2.findTheDistanceValue(a3, b3, 6) << "\n";

    return 0;
}