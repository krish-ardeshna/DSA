#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Cost to Acquire Required Items
// Link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Greedy + Math (Pairs First, Then the Remainder)

// ------------------------------------------------------------
// Approach 1: Brute Force (Try Every Number of "Both" Items)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {
        long long best = LLONG_MAX;

        // b = number of "both" items bought
        for (int b = 0; b <= max(need1, need2); b++) {
            long long cost = (long long)b * costBoth
                           + (long long)max(0, need1 - b) * cost1
                           + (long long)max(0, need2 - b) * cost2;

            best = min(best, cost);
        }

        return best;
    }
};

// ------------------------------------------------------------
// Approach 2: Greedy (Common Part + Remainder)
// ------------------------------------------------------------
class SolutionGreedy {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {
        long long common = min(need1, need2);

        // each of the common units needs one item of type 1 and one of type 2
        long long ans = common * min((long long)costBoth, (long long)cost1 + cost2);

        // the remainder needs only one type, but a "both" item can still be cheaper
        if (need1 > need2)
            ans += (long long)(need1 - need2) * min(costBoth, cost1);
        else
            ans += (long long)(need2 - need1) * min(costBoth, cost2);

        return ans;
    }
};

int main() {
    SolutionBruteForce s1;
    cout << s1.minimumCost(3, 2, 1, 3, 2) << " "
         << s1.minimumCost(5, 4, 15, 2, 3) << " "
         << s1.minimumCost(5, 3, 1, 0, 0) << "\n";

    SolutionGreedy s2;
    cout << s2.minimumCost(3, 2, 1, 3, 2) << " "
         << s2.minimumCost(5, 4, 15, 2, 3) << " "
         << s2.minimumCost(5, 3, 1, 0, 0) << "\n";

    return 0;
}