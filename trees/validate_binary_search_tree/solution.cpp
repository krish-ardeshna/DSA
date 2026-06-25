#include <bits/stdc++.h>
using namespace std;

// Problem: Validate Binary Search Tree
// Link: https://leetcode.com/problems/validate-binary-search-tree/
// Difficulty: Medium
// Pattern: Trees / DFS

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
// Approach 1: Recursion with Valid Range
// ------------------------------------------------------------

class SolutionRecursive {
public:
    bool validate(TreeNode* root, long long low, long long high) {
        if (!root) {
            return true;
        }

        if (root->val <= low || root->val >= high) {
            return false;
        }

        return validate(root->left, low, root->val) &&
               validate(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative Inorder Traversal
// ------------------------------------------------------------

class SolutionIterative {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;

        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (prev && root->val <= prev->val) {
                return false;
            }

            prev = root;
            root = root->right;
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    SolutionIterative s;

    cout << boolalpha << s.isValidBST(root) << "\n";

    return 0;
}