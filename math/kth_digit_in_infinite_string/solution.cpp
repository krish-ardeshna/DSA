#include <bits/stdc++.h>
using namespace std;

// Problem: K-th Digit in Infinite String
// Link: https://leetcode.com/problems/k-th-digit-in-infinite-string/
// Difficulty: Medium (contest problem)  
// Pattern: Math - Digit Position Search (Block Counting)

// ------------------------------------------------------------
// Approach: Digit-Length Block Search
// ------------------------------------------------------------
class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9) {
            return k;
        }

        k -= 9;

        long long start = 1;
        int d = 1;

        while (true) {
            long long end = start * 10 - 1;
            long long blocks = end - start + 1;

            long long blockSize = 10LL * (d + 1);
            long long total = blocks * blockSize;

            if (k > total) {
                k -= total;
                start *= 10;
                d++;
            }
            else {
                long long blockIndex = (k - 1) / blockSize;
                long long b = start + blockIndex;

                long long pos = (k - 1) % blockSize;
                long long numberIndex = pos / (d + 1);

                int digitIndex = pos % (d + 1);

                long long num;

                if (b % 2 == 0) {
                    num = 10 * b + numberIndex;
                }
                else {
                    num = 10 * b + 9 - numberIndex;
                }

                string s = to_string(num);

                return s[digitIndex] - '0';
            }
        }
    }
};

int main() {
    Solution obj;
    cout << obj.kthDigit(15);
    return 0;
}