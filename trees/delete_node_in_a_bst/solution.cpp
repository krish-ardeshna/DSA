#include <bits/stdc++.h>
using namespace std;

// Problem: Delete Node in a BST
// Link: https://leetcode.com/problems/delete-node-in-a-bst/
// Difficulty: Medium
// Pattern: BST - Iterative Search + Splice-Out Deletion

// ------------------------------------------------------------
// Approach: Locate Parent Iteratively, Splice Left Subtree Under Predecessor
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
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == nullptr) return root;
        return findLastRight(root->right);
    }
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) return root->right;
        else if (root->right == nullptr) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);

        lastRight->right = rightChild;

        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) return helper(root);
        TreeNode* dummy = root;
        while (root != nullptr) {
            if (root->val > key) {
                if (root->left != nullptr && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            }
            else {
                if (root->right != nullptr && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution obj;
    TreeNode* result = obj.deleteNode(root, 3);

    cout << result->val;
    return 0;
}