#include <bits/stdc++.h>
using namespace std;

// Problem: Count Non-Decreasing Subarrays After K Operations
// Link: https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/
// Difficulty: Hard
// Pattern: Prefix Maximum Cost + Two Pointers (Binary Lifting on Next Greater / Monotonic Deque)

// Cost to make a subarray non-decreasing with +1 operations:
//   sum of (prefix maximum - element), where the prefix maximum starts at the subarray's left end.

// ------------------------------------------------------------
// Approach 1: Brute Force (Extend Every Start Until the Cost Exceeds k)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;

        for (int l = 0; l < n; l++) {
            long long mx = 0, cost = 0;

            for (int r = l; r < n; r++) {
                mx = max(mx, (long long)nums[r]);
                cost += mx - nums[r];

                // the cost only grows as r grows, so stop at the first failure
                if (cost > k)
                    break;

                ans++;
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Two Pointers + Binary Lifting on Next Greater Element
// ------------------------------------------------------------
class SolutionBinaryLifting {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> nxt(n, n), st;

        // Find the next strictly greater element.
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                nxt[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        // Binary lifting preprocessing.
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                int mid = up[j - 1][i];

                up[j][i] = up[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // Sum of prefix maximums in [l, r].
        auto getCost = [&](int l, int r) -> long long {
            long long total = 0;
            int pos = l;

            for (int j = LOG - 1; j >= 0; j--) {
                int next = up[j][pos];

                if (next <= r + 1) {
                    total += sum[j][pos];
                    pos = next;
                }
            }

            if (pos <= r)
                total += 1LL * nums[pos] * (r - pos + 1);

            return total - (pref[r + 1] - pref[l]);
        };

        // Sliding window.
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (getCost(left, right) > k)
                left++;

            ans += right - left + 1;
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: Two Pointers + Monotonic Deque (Left to Right Sweep Backwards)
// ------------------------------------------------------------
class SolutionDeque {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // The deque holds the prefix-maximum chain of the window [l, r]:
        // (value, how many positions of the window have this prefix maximum).
        // The front is next to l, the back is next to r.
        deque<pair<long long, long long>> dq;

        long long cur = 0;   // sum of value * length over the deque
        long long ans = 0;
        int r = n - 1;

        // l goes from right to left, so the valid r can only move left
        for (int l = n - 1; l >= 0; l--) {
            // add nums[l] at the front, it absorbs every smaller or equal segment
            long long len = 1;

            while (!dq.empty() && dq.front().first <= nums[l]) {
                len += dq.front().second;
                cur -= dq.front().first * dq.front().second;
                dq.pop_front();
            }

            dq.push_front({nums[l], len});
            cur += 1LL * nums[l] * len;

            // shrink the window from the right until the cost is at most k
            while (cur - (pref[r + 1] - pref[l]) > k) {
                cur -= dq.back().first;
                dq.back().second--;

                if (dq.back().second == 0)
                    dq.pop_back();

                r--;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};

int main() {
    vector<int> a1 = {6, 3, 1, 2, 4, 4};
    vector<int> a2 = {6, 3, 1, 3, 6};

    SolutionBruteForce s1;
    cout << s1.countNonDecreasingSubarrays(a1, 7) << " "
         << s1.countNonDecreasingSubarrays(a2, 4) << "\n";

    SolutionBinaryLifting s2;
    cout << s2.countNonDecreasingSubarrays(a1, 7) << " "
         << s2.countNonDecreasingSubarrays(a2, 4) << "\n";

    SolutionDeque s3;
    cout << s3.countNonDecreasingSubarrays(a1, 7) << " "
         << s3.countNonDecreasingSubarrays(a2, 4) << "\n";

    return 0;
}