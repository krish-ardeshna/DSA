#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Depth of Binary Tree
// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Difficulty: Easy
// Pattern: Tree - DFS (Recursion) / BFS (Queue) / DFS (Iterative Stack)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach 1: Recursive DFS
// ------------------------------------------------------------
class SolutionDFSRecursive {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// ------------------------------------------------------------
// Approach 2: BFS (Queue) — stops at first leaf found
// ------------------------------------------------------------
class SolutionBFS {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            if (!node->left && !node->right)
                return depth;

            if (node->left)
                q.push({node->left, depth + 1});

            if (node->right)
                q.push({node->right, depth + 1});
        }

        return 0;
    }
};

// ------------------------------------------------------------
// Approach 3: DFS (Iterative, Explicit Stack)
// ------------------------------------------------------------
class SolutionDFSIterative {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int ans = INT_MAX;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();

            if (!node->left && !node->right) {
                ans = min(ans, depth);
            }

            if (node->left)
                st.push({node->left, depth + 1});

            if (node->right)
                st.push({node->right, depth + 1});
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    SolutionDFSRecursive s1;
    cout << s1.minDepth(root) << "\n";

    SolutionBFS s2;
    cout << s2.minDepth(root) << "\n";

    SolutionDFSIterative s3;
    cout << s3.minDepth(root) << "\n";

    return 0;
}