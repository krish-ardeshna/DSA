#include <bits/stdc++.h>
using namespace std;

// Problem: Find Center of Star Graph
// Link: https://leetcode.com/problems/find-center-of-star-graph/
// Difficulty: Easy
// Pattern: Graph

// ------------------------------------------------------------
// Approach 1: Frequency Map
// ------------------------------------------------------------

class SolutionFrequency {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m = edges.size();
        unordered_map<int, int> freq;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < 2; j++) {
                freq[edges[i][j]]++;
            }
        }

        for(auto &[node, count] : freq) {
            if(count == m) {
                return node;
            }
        }

        return -1;
    }
};

// ------------------------------------------------------------
// Approach 2: Count Candidate Occurrences
// ------------------------------------------------------------

class SolutionCounting {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m = edges.size();

        int c1 = edges[0][0];
        int c2 = edges[0][1];

        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < m; i++) {
            if(edges[i][0] == c1 || edges[i][1] == c1) {
                count1++;
            }

            if(edges[i][0] == c2 || edges[i][1] == c2) {
                count2++;
            }
        }

        if(count1 == m) {
            return c1;
        }

        return c2;
    }
};

// ------------------------------------------------------------
// Approach 3: Observation (Optimal)
// ------------------------------------------------------------

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }

        return edges[0][1];
    }
};

int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};

    Solution s;
    cout << s.findCenter(edges) << "\n";

    return 0;
}