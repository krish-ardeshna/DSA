#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Pivot Integer
// Link: https://leetcode.com/problems/find-the-pivot-integer/
// Difficulty: Easy
// Pattern: Prefix Sum / Math

// ------------------------------------------------------------
// Approach 1: Prefix Sum Simulation
// ------------------------------------------------------------

class SolutionPrefixSum {
public:
    int pivotInteger(int n) {

        int totalSum = n * (n + 1) / 2;
        int leftSum = 0;

        for (int i = 1; i <= n; i++) {

            leftSum += i;
            int rightSum = totalSum - leftSum + i;

            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};

// ------------------------------------------------------------
// Approach 2: Mathematical Observation
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int pivotInteger(int n) {

        int sum = n * (n + 1) / 2;
        int pivot = sqrt(sum);

        return (pivot * pivot == sum) ? pivot : -1;
    }
};

int main() {
    int n = 8;

    SolutionOptimal s;
    cout << s.pivotInteger(n) << "\n";
    
    return 0;
}