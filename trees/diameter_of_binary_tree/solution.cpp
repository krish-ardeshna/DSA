#include <bits/stdc++.h>
using namespace std;

// Problem: Diameter of Binary Tree
// Link: https://leetcode.com/problems/diameter-of-binary-tree/
// Difficulty: Easy
// Pattern: Tree - DFS (Height + Diameter via Reference Parameter)

// ------------------------------------------------------------
// Approach: Post-Order DFS, Track Diameter by Reference While Computing Height
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
    int height(TreeNode* root, int& diameter) {
        if (root == nullptr) return 0;

        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    cout << obj.diameterOfBinaryTree(root);
    return 0;
}