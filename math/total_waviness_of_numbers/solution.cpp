#include <bits/stdc++.h>
using namespace std;

// Problem: Total Waviness of Numbers in Range I
// Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
// Difficulty: Medium
// Pattern: Math / Digit Manipulation

// ------------------------------------------------------------
// Approach 1: Vector of Digits
// ------------------------------------------------------------

class SolutionVector {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int num = num1; num <= num2; num++) {
            vector<int> digits;

            int n = num;

            while (n > 0) {
                digits.push_back(n % 10);
                n /= 10;
            }

            reverse(digits.begin(), digits.end());

            if (digits.size() < 3) {
                continue;
            }

            for (int i = 1; i < digits.size() - 1; i++) {

                int left = digits[i - 1];
                int middle = digits[i];
                int right = digits[i + 1];

                if ((middle > left && middle > right) ||
                    (middle < left && middle < right)) {
                    total++;
                }
            }
        }
        return total;
    }
};

// ------------------------------------------------------------
// Approach 2: String Conversion
// ------------------------------------------------------------

class SolutionString {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int num = num1; num <= num2; num++) {
            string s = to_string(num);

            if (s.length() < 3) {
                continue;
            }

            for (int i = 1; i < s.length() - 1; i++) {
                if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                    (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                    total++;
                }
            }
        }
        return total;
    }
};

// ------------------------------------------------------------
// Approach 3: Direct Digit Processing
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;

        for (int i = num1; i <= num2; i++) {
            count += wavy(i);
        }
        return count;
    }

private:
    int wavy(int n) {
        if (n < 100) {
            return 0;
        }

        int count = 0;

        int left;
        int middle;
        int right;

        right = n % 10;
        n /= 10;

        middle = n % 10;
        n /= 10;

        while (n > 0) {

            left = n % 10;

            if ((middle > left && middle > right) ||
                (middle < left && middle < right)) {
                count++;
            }

            right = middle;
            middle = left;

            n /= 10;
        }
        return count;
    }
};

int main() {
    int num1 = 100;
    int num2 = 120;

    SolutionOptimal s;

    cout << s.totalWaviness(num1, num2) << "\n";

    return 0;
}