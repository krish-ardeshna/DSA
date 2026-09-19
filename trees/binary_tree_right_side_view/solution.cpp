#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty: Medium
// Pattern: Tree - DFS (Right-First Traversal, First Visit Per Level)

// ------------------------------------------------------------
// Approach: Recursive DFS, Visit Right Before Left, Record First Node Per Level
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
    void recursion(TreeNode* root, int level, vector<int> &res) {
        if (root == nullptr) return;
        if (res.size() == level) res.push_back(root->val);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> result = obj.rightSideView(root);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}