#include <bits/stdc++.h>
using namespace std;

// Problem: Count Nodes Equal to Average of Subtree
// Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// Difficulty: Medium
// Pattern: Tree - Post-Order DFS (Sum + Count Aggregation)

// ------------------------------------------------------------
// Approach: Post-Order DFS Returning Subtree Sum and Node Count
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
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

public:
    int averageOfSubtree(TreeNode* root) {

        solve(root);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    Solution obj;
    cout << obj.averageOfSubtree(root);
    return 0;
}