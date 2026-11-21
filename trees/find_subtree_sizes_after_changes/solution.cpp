#include <bits/stdc++.h>
using namespace std;

// Problem: Find Subtree Sizes After Changes
// Link: https://leetcode.com/problems/find-subtree-sizes-after-changes/
// Difficulty: Medium
// Pattern: Tree DFS + Nearest Ancestor with the Same Character (Last Occurrence Array)

// Every node x (except the root) is moved, at the same time, under its CLOSEST ancestor y
// that has the same character, when such a y exists. Ancestors are taken from the ORIGINAL tree.

// ------------------------------------------------------------
// Approach 1: Brute Force (Walk Up for the Ancestor, Walk Up to Count Sizes)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<int> newParent(parent);

        // closest ancestor in the original tree with the same character
        for (int x = 1; x < n; x++) {
            int y = parent[x];

            while (y != -1 && s[y] != s[x])
                y = parent[y];

            if (y != -1)
                newParent[x] = y;
        }

        // every node adds 1 to each of its ancestors in the new tree
        vector<int> answer(n, 1);

        for (int x = 1; x < n; x++) {
            int y = newParent[x];

            while (y != -1) {
                answer[y]++;
                y = newParent[y];
            }
        }

        return answer;
    }
};

// ------------------------------------------------------------
// Approach 2: DFS (Last Occurrence per Character) + DFS for Sizes
// ------------------------------------------------------------
class SolutionDFS {
public:
    vector<int> answer;
    vector<vector<int>> adj;

    int dfs(int node, vector<vector<int>>& tree) {
        int size = 1;

        for (int child : tree[node]) {
            size += dfs(child, tree);
        }

        answer[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.assign(n, {});
        answer.assign(n, 0);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // last[c] = closest ancestor of the current node with character c (-1 if none)
        vector<int> last(26, -1);
        vector<int> newParent(n, -1);

        function<void(int)> findParent = [&](int node) {
            int c = s[node] - 'a';

            int old = last[c];

            if (old != -1) {
                newParent[node] = old;
            } else {
                newParent[node] = parent[node];
            }

            last[c] = node;

            for (int child : adj[node]) {
                findParent(child);
            }

            last[c] = old;
        };

        findParent(0);

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        dfs(0, tree);

        return answer;
    }
};

// ------------------------------------------------------------
// Approach 3: Iterative DFS + Sizes in Reverse Order (No Recursion, No Second Tree)
// ------------------------------------------------------------
class SolutionIterative {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        vector<int> last(26, -1);
        vector<int> newParent(n, -1);
        vector<int> order;   // nodes in the order they are first visited

        // stack entry: (node, previous last[c] to restore, is this the exit marker)
        struct Entry {
            int node, old;
            bool exit;
        };

        vector<Entry> st;
        st.push_back({0, -1, false});

        while (!st.empty()) {
            Entry e = st.back();
            st.pop_back();

            int c = s[e.node] - 'a';

            if (e.exit) {
                last[c] = e.old;
                continue;
            }

            int node = e.node;
            int old = last[c];

            newParent[node] = (old != -1) ? old : parent[node];
            last[c] = node;
            order.push_back(node);

            // the exit marker is popped after the whole subtree is done
            st.push_back({node, old, true});

            for (int child : adj[node])
                st.push_back({child, -1, false});
        }

        // the new parent of a node is one of its original ancestors, so it appears
        // earlier in order. Going backwards adds every node to its new parent
        // only after the node's own size is final.
        vector<int> answer(n, 1);

        for (int i = n - 1; i >= 1; i--) {
            int v = order[i];
            answer[newParent[v]] += answer[v];
        }

        return answer;
    }
};

void print(vector<int> v) {
    for (int a : v) cout << a << " ";
    cout << "| ";
}

int main() {
    vector<int> p1 = {-1, 0, 0, 1, 1, 1};
    string s1 = "abaabc";

    vector<int> p2 = {-1, 0, 4, 0, 1};
    string s2 = "abbba";

    SolutionBruteForce b;
    print(b.findSubtreeSizes(p1, s1));
    print(b.findSubtreeSizes(p2, s2));
    cout << "\n";

    SolutionDFS d;
    print(d.findSubtreeSizes(p1, s1));
    print(SolutionDFS().findSubtreeSizes(p2, s2));
    cout << "\n";

    SolutionIterative it;
    print(it.findSubtreeSizes(p1, s1));
    print(it.findSubtreeSizes(p2, s2));
    cout << "\n";

    return 0;
}