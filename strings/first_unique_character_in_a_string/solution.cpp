#include <bits/stdc++.h>
using namespace std;

// Problem: First Unique Character in a String
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/
// Difficulty: Easy
// Pattern: String, Frequency Counting

// ------------------------------------------------------------
// Approach 1: Hash Map Frequency
// ------------------------------------------------------------

class SolutionHashMap {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

// ------------------------------------------------------------
// Approach 2: Frequency Array
// ------------------------------------------------------------

class SolutionArray {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

// ------------------------------------------------------------
// Approach 3: Queue + Frequency (Streaming)
// ------------------------------------------------------------

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        queue<pair<char, int>> q;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            q.push({s[i], i});

            while (!q.empty() && freq[q.front().first - 'a'] > 1)
                q.pop();
        }

        return q.empty() ? -1 : q.front().second;
    }
};

int main() {
    string s = "leetcode";

    Solution obj;
    cout << obj.firstUniqChar(s) << endl;

    return 0;
}