#include <bits/stdc++.h>
using namespace std;

// Problem: Unique 3-Digit Even Numbers
// Link: https://leetcode.com/problems/unique-3-digit-even-numbers/
// Difficulty: Medium
// Pattern: Combinatorics (Frequency Check) / Brute Force Permutation + Set

// ------------------------------------------------------------
// Approach 1: Frequency Count + Combinatorial Digit-Slot Check
// ------------------------------------------------------------
class SolutionFrequencyCheck {
public:
    int totalNumbers(vector<int>& digits) {

        vector<int> freq(10, 0);

        for (int digit : digits) {
            freq[digit]++;
        }

        int ans = 0;

        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 8; k += 2) {

                    vector<int> used(10, 0);

                    used[i]++;
                    used[j]++;
                    used[k]++;

                    bool possible = true;

                    for (int d = 0; d <= 9; d++) {
                        if (used[d] > freq[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if (possible) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Brute Force Index Permutation + Set Deduplication
// ------------------------------------------------------------
class SolutionBruteForcePermutation {
public:
    int totalNumbers(vector<int>& digits) {

        set<int> st;

        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {

                    if (i == j || j == k || i == k)
                        continue;

                    if (digits[i] == 0)
                        continue;

                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100 +
                              digits[j] * 10 +
                              digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};

int main() {
    vector<int> digits = {2, 1, 3, 0};

    SolutionFrequencyCheck s1;
    cout << s1.totalNumbers(digits) << "\n";

    SolutionBruteForcePermutation s2;
    cout << s2.totalNumbers(digits) << "\n";

    return 0;
}