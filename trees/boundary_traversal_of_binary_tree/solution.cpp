#include <bits/stdc++.h>
using namespace std;

// Problem: Boundary Traversal of Binary Tree
// Link: https://leetcode.com/problems/boundary-of-binary-tree/
// Difficulty: Medium
// Pattern: Tree - DFS (Left Boundary + Leaves + Right Boundary Combined)

// ------------------------------------------------------------
// Approach: Three-Part Traversal (Left Boundary, Leaves, Reversed Right Boundary)
// ------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    void leftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;

        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->val);
            }

            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void rightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->val);
            }

            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        reverse(temp.begin(), temp.end());

        for (int value : temp) {
            res.push_back(value);
        }
    }

    void leaves(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }

        if (root->left) {
            leaves(root->left, res);
        }

        if (root->right) {
            leaves(root->right, res);
        }
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> res;

        if (root == nullptr) {
            return res;
        }

        if (isLeaf(root)) {
            res.push_back(root->val);
            return res;
        }

        res.push_back(root->val);

        leftBoundary(root, res);
        leaves(root, res);
        rightBoundary(root, res);

        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<int> result = obj.boundary(root);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}