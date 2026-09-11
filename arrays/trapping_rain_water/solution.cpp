#include <bits/stdc++.h>
using namespace std;

// Problem: Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water/
// Difficulty: Hard
// Pattern: Two Pointer / Prefix Max + Suffix Max

// ------------------------------------------------------------
// Approach 1: Two Pointer (O(1) Space)
// ------------------------------------------------------------
class SolutionTwoPointer {
public:
    int trap(vector<int>& height) {

        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            if (height[l] < height[r]) {

                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    water += leftMax - height[l];

                l++;
            }
            else {

                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    water += rightMax - height[r];

                r--;
            }
        }

        return water;
    }
};

// ------------------------------------------------------------
// Approach 2: Prefix Max + Suffix Max Arrays
// ------------------------------------------------------------
class SolutionPrefixSuffix {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        vector<int> prefixMax(n);
        vector<int> suffixMax(n);

        prefixMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            int leftMax = max(prefixMax[i - 1], height[i]);
            prefixMax[i] = leftMax;
        }

        suffixMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int rightMax = max(suffixMax[i + 1], height[i]);
            suffixMax[i] = rightMax;
        }

        for (int i = 0; i < n; i++) {
            water += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return water;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    SolutionTwoPointer s1;
    cout << s1.trap(height) << "\n";

    SolutionPrefixSuffix s2;
    cout << s2.trap(height) << "\n";

    return 0;
}