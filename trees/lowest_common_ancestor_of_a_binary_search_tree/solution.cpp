#include <bits/stdc++.h>
using namespace std;

// Problem: Lowest Common Ancestor of a Binary Search Tree
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Difficulty: Medium
// Pattern: BST - Recursive Descent Using Ordering

// ------------------------------------------------------------
// Approach: Follow Single Path Determined by BST Property
// ------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        int curr = root->val;

        if (curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    Solution obj;
    TreeNode* result = obj.lowestCommonAncestor(root, root->left, root->left->right);

    cout << result->val;
    return 0;
}