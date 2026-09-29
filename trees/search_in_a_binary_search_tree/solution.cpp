#include <bits/stdc++.h>
using namespace std;

// Problem: Search in a Binary Search Tree
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Difficulty: Easy
// Pattern: BST - Iterative Binary Search Descent

// ------------------------------------------------------------
// Approach: Iterative Descent Using BST Ordering
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    TreeNode* result = obj.searchBST(root, 2);

    if (result) cout << result->val;
    else cout << "Not found";

    return 0;
}