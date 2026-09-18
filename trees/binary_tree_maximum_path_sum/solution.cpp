#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Tree Maximum Path Sum
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Difficulty: Hard
// Pattern: Tree - DFS (Max Gain + Global Max via Reference)

// ------------------------------------------------------------
// Approach: Post-Order DFS, Clamp Negative Gains, Track Global Sum by Reference
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
    int maxPath(TreeNode* root, int &sum) {
        if (root == nullptr) return 0;

        int left = max(0, maxPath(root->left, sum));
        int right = max(0, maxPath(root->right, sum));

        sum = max(sum, left + right + root->val);

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxPath(root, sum);
        return sum;
    }
};

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << obj.maxPathSum(root);
    return 0;
}