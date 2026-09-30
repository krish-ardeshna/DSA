#include <bits/stdc++.h>
using namespace std;

// Problem: Insert into a Binary Search Tree
// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Difficulty: Medium
// Pattern: BST - Iterative Descent to Find Insertion Spot

// ------------------------------------------------------------
// Approach: Iterative Walk Down, Attach New Node at First Null Slot
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* curr = root;
        while (true) {
            if (curr->val <= val) {
                if (curr->right != nullptr) curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->left != nullptr) curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    Solution obj;
    TreeNode* result = obj.insertIntoBST(root, 5);

    cout << result->val;
    return 0;
}