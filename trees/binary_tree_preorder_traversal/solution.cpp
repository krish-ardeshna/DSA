#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Tree Preorder Traversal
// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Difficulty: Easy
// Pattern: Binary Tree / DFS

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach: Iterative Preorder Traversal using Stack
// ------------------------------------------------------------

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if (node->right) {
                st.push(node->right);
            }

            if (node->left) {
                st.push(node->left);
            }
        }

        return ans;
    }
};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    vector<int> ans = s.preorderTraversal(root);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}