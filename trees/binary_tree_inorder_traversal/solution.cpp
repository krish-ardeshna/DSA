#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
// Approach 1: Iterative Inorder Traversal using Stack
// ------------------------------------------------------------

class SolutionIterative {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Recursive Inorder Traversal
// ------------------------------------------------------------

class SolutionRecursive {
public:
    vector<int> ans;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    SolutionRecursive s;
    vector<int> ans = s.inorderTraversal(root);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}