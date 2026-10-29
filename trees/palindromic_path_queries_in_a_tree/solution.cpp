#include <bits/stdc++.h>
using namespace std;

// Problem: Palindromic Path Queries in a Tree
// Link: https://leetcode.com/problems/palindromic-path-queries-in-a-tree/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Tree + Bitmask Parity (Euler Tour + Fenwick + Binary Lifting, Heavy-Light Decomposition)

// A path can be rearranged into a palindrome when at most ONE letter appears an odd
// number of times. Keep a 26-bit mask per path (bit c = parity of letter c); the answer
// is yes when (mask & (mask - 1)) == 0.

// ------------------------------------------------------------
// Approach 1: Euler Tour + Fenwick (Range XOR, Point Query) + Binary Lifting LCA
// ------------------------------------------------------------
class SolutionEulerFenwick {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        // XOR val into every position in [l, r)  (0-indexed, r exclusive)
        void rangeXor(int l, int r, int val) {
            update(l + 1, val);
            if (r < n)
                update(r + 1, val);
        }
    };

    int LOG;
    vector<vector<int>> up;
    vector<int> depth;

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k))
                u = up[k][u];
        }

        if (u == v)
            return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);

        // pref[u] = parity mask of the path root -> u (original letters)
        vector<int> parent(n, -1), tin(n), tout(n), pref(n), order;
        order.reserve(n);

        stack<int> st;
        st.push(0);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = order.size();
            order.push_back(u);

            pref[u] = (u == 0 ? 0 : pref[parent[u]]) ^
                      (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push(v);
            }
        }

        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        // subtree of u is the tin range [tin[u], tout[u])
        vector<int> sz(n, 1);

        for (int i = n - 1; i > 0; i--)
            sz[parent[order[i]]] += sz[order[i]];

        for (int u = 0; u < n; u++)
            tout[u] = tin[u] + sz[u];

        // Fenwick holds the XOR of all updates that cover a node
        Fenwick fw(n);
        vector<bool> ans;

        for (const string& q : queries) {
            string op, c;
            int u, v;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int delta = (1 << (s[u] - 'a')) ^
                            (1 << (c[0] - 'a'));

                if (delta)
                    fw.rangeXor(tin[u], tout[u], delta);

                s[u] = c[0];
            } else {
                ss >> v;

                int w = lca(u, v);

                int pu = pref[u] ^ fw.query(tin[u] + 1);
                int pv = pref[v] ^ fw.query(tin[v] + 1);

                // root->u and root->v cancel everything above w, but also w itself, so add w back
                int mask = pu ^ pv ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Heavy-Light Decomposition + Fenwick (Point Update, Path XOR Query)
// ------------------------------------------------------------
class SolutionHLD {
    int n;
    vector<int> bit;

    // Fenwick over HLD positions: stores the letter bit of each node, prefix XOR query
    void update(int i, int val) {
        for (i++; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int prefix(int i) {              // XOR of positions [0, i)
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    int rangeXor(int l, int r) {     // XOR of positions [l, r]
        return prefix(r + 1) ^ prefix(l);
    }

public:
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        n = n_;
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // 1) parent, depth, and an order where every parent comes before its children
        vector<int> parent(n, -1), depth(n, 0), order;
        order.reserve(n);
        order.push_back(0);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        // 2) subtree sizes and the heavy child of every node
        vector<int> sz(n, 1), heavy(n, -1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            int p = parent[u];
            if (heavy[p] == -1 || sz[u] > sz[heavy[p]])
                heavy[p] = u;
        }

        // 3) chains: every chain gets a block of consecutive positions, top to bottom
        vector<int> head(n), pos(n);
        int cur = 0;

        for (int u : order) {
            if (u == 0 || heavy[parent[u]] != u) {
                for (int v = u; v != -1; v = heavy[v]) {
                    head[v] = u;
                    pos[v] = cur++;
                }
            }
        }

        // 4) build the Fenwick with the starting letters
        bit.assign(n + 1, 0);
        for (int u = 0; u < n; u++)
            update(pos[u], 1 << (s[u] - 'a'));

        vector<bool> ans;

        for (const string& q : queries) {
            string op, c;
            int u, v;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int delta = (1 << (s[u] - 'a')) ^
                            (1 << (c[0] - 'a'));

                if (delta)
                    update(pos[u], delta);

                s[u] = c[0];
            } else {
                ss >> v;

                int mask = 0;

                // climb chain by chain until both nodes share a chain
                while (head[u] != head[v]) {
                    if (depth[head[u]] < depth[head[v]])
                        swap(u, v);

                    mask ^= rangeXor(pos[head[u]], pos[u]);
                    u = parent[head[u]];
                }

                if (depth[u] > depth[v])
                    swap(u, v);

                mask ^= rangeXor(pos[u], pos[v]);

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};

int main() {
    // path 0 - 1 - 2 with letters a, a, b
    int n1 = 3;
    vector<vector<int>> e1 = {{0, 1}, {1, 2}};
    string s1 = "aab";
    vector<string> q1 = {"query 0 2", "update 1 b", "query 0 2", "update 2 c", "query 0 2", "query 1 1"};

    // branching tree: 0 is the root, 1 and 2 are its children, 3 and 4 are children of 1
    int n2 = 5;
    vector<vector<int>> e2 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    string s2 = "abcba";
    vector<string> q2 = {"query 3 2", "update 2 a", "query 3 2", "query 3 4"};

    SolutionEulerFenwick a;
    SolutionHLD b;

    cout << boolalpha;

    for (bool x : a.palindromePath(n1, e1, s1, q1)) cout << x << " ";
    cout << "\n";
    for (bool x : a.palindromePath(n2, e2, s2, q2)) cout << x << " ";
    cout << "\n";

    for (bool x : b.palindromePath(n1, e1, s1, q1)) cout << x << " ";
    cout << "\n";
    for (bool x : b.palindromePath(n2, e2, s2, q2)) cout << x << " ";
    cout << "\n";

    return 0;
}