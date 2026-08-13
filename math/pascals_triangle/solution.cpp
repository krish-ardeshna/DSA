#include <bits/stdc++.h>
using namespace std;

// Problem: Pascal's Triangle
// Link: https://leetcode.com/problems/pascals-triangle/
// Difficulty: Easy
// Pattern: Math (Combinatorics) / DP (Build from Previous Row)

// ------------------------------------------------------------
// Approach 1: Combinatorics Formula (nCr Incremental)
// ------------------------------------------------------------
class SolutionCombinatorics {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> res;
        res.push_back(1);
        for (int col = 1; col <= row; col++) {
            ans = ans * (row - col + 1);
            ans = ans / (col);
            res.push_back(ans);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;

        for (int i = 0; i < numRows; i++) {
            pascal.push_back(generateRow(i));
        }
        return pascal;
    }
};

// ------------------------------------------------------------
// Approach 2: DP (Build from Previous Row)
// ------------------------------------------------------------
class SolutionDP {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    SolutionCombinatorics s1;
    vector<vector<int>> r1 = s1.generate(5);
    for (auto& row : r1) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }

    SolutionDP s2;
    vector<vector<int>> r2 = s2.generate(5);
    for (auto& row : r2) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }

    return 0;
}