#include<bits/stdc++.h>
using namespace std;

// Problem: Rotate Image
// Link: https://leetcode.com/problems/rotate-image/
// Platform: LeetCode
// Pattern: Matrix Manipulation (Transpose + Reverse)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    s.rotate(matrix);

    for(auto& row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}