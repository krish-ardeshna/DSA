#include <bits/stdc++.h>
using namespace std;

// Problem: Count Complete Tree Nodes
// Link: https://leetcode.com/problems/count-complete-tree-nodes/
// Difficulty: Medium
// Pattern: Tree - Binary Search Style Recursion (Exploit Complete Tree Property)

// ------------------------------------------------------------
// Approach: Compare Left-Edge and Right-Edge Heights to Detect Perfect Subtrees
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
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution obj;
    cout << obj.countNodes(root);
    return 0;
}