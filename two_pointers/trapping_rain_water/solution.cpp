#include <bits/stdc++.h>
using namespace std;

// Problem: Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water/
// Difficulty: Hard
// Pattern: Two Pointers

// ------------------------------------------------------------
// Approach: Two Pointers
// ------------------------------------------------------------

class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (left < right) {

            if (height[left] < height[right]) {

                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    water += leftMax - height[left];
                }

                left++;
            }
            else {

                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    water += rightMax - height[right];
                }
                
                right--;
            }
        }
        return water;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;

    cout << s.trap(height) << "\n";
    return 0;
}