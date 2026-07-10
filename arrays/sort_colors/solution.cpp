#include <bits/stdc++.h>
using namespace std;

// Problem: Sort Colors
// Link: https://leetcode.com/problems/sort-colors/
// Difficulty: Medium
// Pattern: Arrays / Two Pointers

// ------------------------------------------------------------
// Approach 1: Counting Sort
// ------------------------------------------------------------

class SolutionCounting {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for (int num : nums) {
            if (num == 0) {
                count0++;
            }
            else if (num == 1) {
                count1++;
            }
            else {
                count2++;
            }
        }

        int index = 0;
        while (count0--) {
            nums[index++] = 0;
        }
        while (count1--) {
            nums[index++] = 1;
        }
        while (count2--) {
            nums[index++] = 2;
        }
    }
};

// ------------------------------------------------------------
// Approach 2: Dutch National Flag Algorithm
// ------------------------------------------------------------

class SolutionOptimal {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    SolutionOptimal s;

    s.sortColors(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}