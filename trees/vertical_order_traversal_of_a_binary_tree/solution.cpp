#include <bits/stdc++.h>
using namespace std;

// Problem: Vertical Order Traversal of a Binary Tree
// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Difficulty: Hard
// Pattern: Tree - BFS + Nested Ordered Maps (Column, Row, Sorted Values)

// ------------------------------------------------------------
// Approach: BFS with (x, y) Coordinates, Nested Map + Multiset for Ordering
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> store;

        store.push({root, {0, 0}});

        while (!store.empty()) {
            auto p = store.front();
            store.pop();

            TreeNode* node = p.first;

            int x = p.second.first, y = p.second.second;

            nodes[x][y].insert(node->val);

            if (node->left) store.push({node->left, {x - 1, y + 1}});
            if (node->right) store.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;

            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> result = obj.verticalTraversal(root);

    for (auto& col : result) {
        for (int v : col) cout << v << " ";
        cout << "\n";
    }

    return 0;
}