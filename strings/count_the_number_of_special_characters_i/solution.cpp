#include <bits/stdc++.h>
using namespace std;

// Problem: Count the Number of Special Characters I
// Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/
// Difficulty: Easy
// Pattern: Strings / Hashing

// ------------------------------------------------------------
// Approach 1: Boolean Array
// ------------------------------------------------------------

class SolutionArray {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26] = {false};
        bool upper[26] = {false};

        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a'] = true;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                upper[ch - 'A'] = true;
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                count++;
            }
        }
        return count;
    }
};

// ------------------------------------------------------------
// Approach 2: Using Sets
// ------------------------------------------------------------

class SolutionSet {
public:
    int numberOfSpecialChars(string word) {
        set<char> lower;
        set<char> upper;

        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                lower.insert(ch);
            }
            else if (ch >= 'A' && ch <= 'Z') {
                upper.insert(tolower(ch));
            }
        }

        int count = 0;

        for (char ch : lower) {
            if (upper.count(ch)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    string word = "aaAbcBC";
    SolutionArray s;

    cout << s.numberOfSpecialChars(word) << "\n";

    return 0;
}