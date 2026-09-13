#include <bits/stdc++.h>
using namespace std;

// Problem: Maximal Rectangle
// Link: https://leetcode.com/problems/maximal-rectangle/
// Difficulty: Hard
// Pattern: Monotonic Stack (Histogram Reduction per Row)

// ------------------------------------------------------------
// Approach: Column Height Accumulation + Largest Rectangle in Histogram per Row
// ------------------------------------------------------------
class Solution {
public:

    int largestRectangle(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > curr) {
                int h = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) width = i;
                else width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;

        vector<vector<int>> prefixSum(n, vector<int>(m));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '0') sum = 0;
                else sum++;

                prefixSum[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            maxArea = max(
                maxArea,
                largestRectangle(prefixSum[i])
            );
        }

        return maxArea;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << obj.maximalRectangle(matrix);
    return 0;
}