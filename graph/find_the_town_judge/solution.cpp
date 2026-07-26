#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Town Judge
// Link: https://leetcode.com/problems/find-the-town-judge/
// Difficulty: Easy
// Pattern: Graph, Degree Counting

// ------------------------------------------------------------
// Approach 1: Hash Set + Frequency Map
// ------------------------------------------------------------

class SolutionHashing {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> person;
        unordered_map<int, int> trustedCount;

        for (auto &t : trust) {
            person.insert(t[0]);
            trustedCount[t[1]]++;
        }

        for (auto &[p, cnt] : trustedCount) {
            if (!person.count(p) && cnt == n - 1)
                return p;
        }

        return n == 1 ? 1 : -1;
    }
};

// ------------------------------------------------------------
// Approach 2: In-degree & Out-degree
// ------------------------------------------------------------

class SolutionDegree {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for (auto &t : trust) {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};

// ------------------------------------------------------------
// Approach 3: Single Degree Array (Optimal)
// ------------------------------------------------------------

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n + 1, 0);

        for (auto &t : trust) {
            degree[t[0]]--;
            degree[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (degree[i] == n - 1)
                return i;
        }

        return -1;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> trust = {{1,3}, {2,3}};

    Solution s;
    cout << s.findJudge(n, trust) << endl;

    return 0;
}