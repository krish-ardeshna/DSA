#include <bits/stdc++.h>
using namespace std;

// Problem: Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium
// Pattern: Hashing / Strings

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {

            // Create key by sorting characters
            string key = s;
            sort(key.begin(), key.end());

            // Store original string in corresponding group
            mp[key].push_back(s);
        }
        
        vector<vector<string>> ans;

        // Extract grouped anagrams
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);

    for (auto group : res) {
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "\n";
    }
    return 0;
}