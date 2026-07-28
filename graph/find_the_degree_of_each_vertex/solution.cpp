#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Degree of Each Vertex
// Link: https://leetcode.com/problems/find-the-degree-of-each-vertex/
// Difficulty: Easy
// Pattern: Graph, Matrix Traversal

// ------------------------------------------------------------
// Approach: Row-wise Degree Counting
// ------------------------------------------------------------

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> degree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i] += matrix[i][j];
            }
        }

        return degree;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,1},
        {1,0,0},
        {1,0,0}
    };

    Solution s;
    vector<int> ans = s.findDegrees(matrix);

    for (int x : ans)
        cout << x << " ";

    return 0;
}