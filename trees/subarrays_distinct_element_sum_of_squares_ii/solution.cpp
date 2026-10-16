#include <bits/stdc++.h>
using namespace std;

// Problem: Subarrays Distinct Element Sum of Squares II
// Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/
// Difficulty: Hard
// Pattern: Segment Tree (Lazy Range Add, Maintain Sum and Sum of Squares)

// ------------------------------------------------------------
// Approach: Sweep Right Endpoint, Range +1 on Positions Where a Value Is New
// ------------------------------------------------------------
class Solution {
    static const int MOD = 1e9 + 7;

    class SegmentTree {
    public:
        int n;
        vector<long long> sum, sq, lazy;

        SegmentTree(int n) : n(n) {
            sum.assign(4 * n, 0);
            sq.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int l, int r, long long val) {
            long long len = r - l + 1;

            sq[node] = (sq[node]
                + 2 * val * sum[node] % MOD
                + val * val % MOD * len % MOD) % MOD;

            sum[node] = (sum[node] + val * len) % MOD;
            lazy[node] += val;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r)
                return;

            int mid = l + (r - l) / 2;

            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) {
                apply(node, l, r, 1);
                return;
            }

            push(node, l, r);

            int mid = l + (r - l) / 2;

            if (ql <= mid)
                update(node * 2, l, mid, ql, qr);

            if (qr > mid)
                update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        }

        void update(int l, int r) {
            if (l <= r)
                update(1, 0, n - 1, l, r);
        }

        long long getSumSquares() {
            return sq[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegmentTree st(n);
        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            st.update(prev + 1, i);

            last[nums[i]] = i;

            ans = (ans + st.getSumSquares()) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 1};
    cout << obj.sumCounts(nums1) << "\n";

    vector<int> nums2 = {2, 2};
    cout << obj.sumCounts(nums2) << "\n";

    return 0;
}