#include <bits/stdc++.h>
using namespace std;

// Problem: Flatten Binary Tree to Linked List
// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Difficulty: Medium
// Pattern: Tree - In-Place Threading / Iterative Stack / Recursive Reverse Postorder

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach 1: In-Place Threading (O(1) Space, Morris-style)
// ------------------------------------------------------------
class SolutionInPlace {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != NULL) {
                TreeNode* prev = curr->left;

                while (prev->right) {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative Stack-Based
// ------------------------------------------------------------
class SolutionStack {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            if (!st.empty()) node->right = st.top();
            node->left = nullptr;
        }
    }
};

// ------------------------------------------------------------
// Approach 3: Recursive Reverse Postorder (Right, Left, Root)
// ------------------------------------------------------------
class SolutionRecursive {
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;

        prev = root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    SolutionInPlace s1;
    s1.flatten(root);

    for (TreeNode* cur = root; cur != nullptr; cur = cur->right) {
        cout << cur->val << " ";
    }

    return 0;
}
