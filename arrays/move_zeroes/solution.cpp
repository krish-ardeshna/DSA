#include<bits/stdc++.h>
using namespace std;

// Problem: Move Zeroes
// Platform: LeetCode
// Link: https://leetcode.com/problems/move-zeroes/
// Pattern: Two Pointers


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,0,13,15,0};

    s.moveZeroes(nums);

    for(int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}