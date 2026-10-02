#include <bits/stdc++.h>
using namespace std;

// Problem: Recover Binary Search Tree
// Link: https://leetcode.com/problems/recover-binary-search-tree/
// Difficulty: Medium
// Pattern: BST - Inorder Traversal (Detect and Fix Swapped Nodes)

// ------------------------------------------------------------
// Approach: Inorder Traversal, Track First/Middle/Last Violation Nodes
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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        if (prev != nullptr && (root->val < prev->val)) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution obj;
    obj.recoverTree(root);

    cout << root->val << " " << root->left->val << " "
         << root->right->val << " " << root->right->left->val;

    return 0;
}