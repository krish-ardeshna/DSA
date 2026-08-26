#include <bits/stdc++.h>
using namespace std;

// Problem: Search a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Difficulty: Medium
// Pattern: Binary Search (2D Matrix, Two-Level Search)

// ------------------------------------------------------------
// Approach 1: Binary Search on Rows + Binary Search within Row
// ------------------------------------------------------------
class SolutionBinaryRows {
public:
    bool binarySearch(const vector<int>& arr, int n, int target) {
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][m - 1]) {
                return binarySearch(matrix[mid], m, target);
            } else if (matrix[mid][m - 1] < target) {
                low = mid + 1;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            }
        }
        return false;
    }
};

// ------------------------------------------------------------
// Approach 2: Linear Scan Rows + Binary Search within Row
// ------------------------------------------------------------
class SolutionLinearRows {
public:
    bool binarySearch(const vector<int>& arr, int n, int target) {
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
                return binarySearch(matrix[i], m, target);
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    SolutionBinaryRows s1;
    cout << s1.searchMatrix(matrix, 3) << "\n";

    SolutionLinearRows s2;
    cout << s2.searchMatrix(matrix, 3) << "\n";

    return 0;
}