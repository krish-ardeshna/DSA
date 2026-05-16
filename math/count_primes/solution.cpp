#include <bits/stdc++.h>
using namespace std;

// Problem: Count Primes
// Link: https://leetcode.com/problems/count-primes/
// Difficulty: Medium
// Pattern: Math / Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {    
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        // Mark multiples as non-prime
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    cout << s.countPrimes(n) << "\n";

    return 0;
}