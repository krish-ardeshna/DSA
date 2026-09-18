#include <bits/stdc++.h>
using namespace std;

// Problem: Balanced Binary Tree
// Link: https://leetcode.com/problems/balanced-binary-tree/
// Difficulty: Easy
// Pattern: Tree - DFS (Height + Early Termination via Sentinel)

// ------------------------------------------------------------
// Approach: Post-Order DFS Returning -1 as Imbalance Signal
// ------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int dfsHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = dfsHeight(root->left);
        if (lh == -1) return -1;

        int rh = dfsHeight(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << obj.isBalanced(root);
    return 0;
}