#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Tree Zigzag Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Difficulty: Medium
// Pattern: Tree - BFS (Level Order with Direction Flip)

// ------------------------------------------------------------
// Approach: BFS with Index Placement Based on Direction Flag
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool LtoR = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = LtoR ? i : size - i - 1;

                row[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            LtoR = !LtoR;
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    for (auto& level : result) {
        for (int v : level) cout << v << " ";
        cout << "\n";
    }

    return 0;
}