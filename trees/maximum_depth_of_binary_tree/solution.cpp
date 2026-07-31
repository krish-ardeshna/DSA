#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Depth of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Difficulty: Easy
// Pattern: Tree, DFS, BFS

#ifndef LEETCODE_SUBMIT
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
#endif

// ------------------------------------------------------------
// Approach 1: Recursive DFS
// ------------------------------------------------------------

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative DFS (Stack)
// ------------------------------------------------------------

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int ans = 0;

        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();

            ans = max(ans, depth);

            if (node->left)
                st.push({node->left, depth + 1});

            if (node->right)
                st.push({node->right, depth + 1});
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: BFS (Level Order)
// ------------------------------------------------------------

class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};

int main() {
    cout << "This problem uses LeetCode's custom structure/API for testing." << endl;
    return 0;
}