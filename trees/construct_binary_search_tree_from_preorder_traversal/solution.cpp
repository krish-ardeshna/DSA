#include <bits/stdc++.h>
using namespace std;

// Problem: Construct Binary Search Tree from Preorder Traversal
// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Difficulty: Medium
// Pattern: BST - Recursive Build with Upper Bound

// ------------------------------------------------------------
// Approach: Recursive Construction Using an Upper Bound Per Subtree
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};

int main() {
    Solution obj;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = obj.bstFromPreorder(preorder);

    cout << root->val;
    return 0;
}