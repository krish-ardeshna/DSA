#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Celebrity
// Link: https://leetcode.com/problems/find-the-celebrity/
// Difficulty: Medium
// Pattern: Two Pointer Elimination / Brute Force Degree Counting

// ------------------------------------------------------------
// Approach 1: Two Pointer Elimination (O(n))
// ------------------------------------------------------------
class SolutionTwoPointer {
public:
    int celebrity(vector<vector<int>> &mat) {
        int n = mat.size();

        int top = 0;
        int bottom = n - 1;

        while (top < bottom) {
            if (mat[top][bottom] == 1) top++;
            else bottom--;
        }

        int candidate = top;

        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};

// ------------------------------------------------------------
// Approach 2: Brute Force Degree Counting (O(n^2))
// ------------------------------------------------------------
class SolutionDegreeCounting {
public:
    int celebrity(vector<vector<int>> &mat) {
        int n = mat.size();

        vector<int> knowMe(n);
        vector<int> Iknow(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (knowMe[i] == n - 1 && Iknow[i] == 0) return i;
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    SolutionTwoPointer s1;
    cout << s1.celebrity(mat) << "\n";

    SolutionDegreeCounting s2;
    cout << s2.celebrity(mat) << "\n";

    return 0;
}