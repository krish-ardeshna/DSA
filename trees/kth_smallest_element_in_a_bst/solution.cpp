#include <bits/stdc++.h>
using namespace std;

// Problem: Kth Smallest Element in a BST
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Difficulty: Medium
// Pattern: BST - Inorder Traversal (Stack-Based / Morris O(1) Space)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach 1: Iterative Stack-Based Inorder
// ------------------------------------------------------------
class SolutionStack {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (--k == 0)
                return curr->val;

            curr = curr->right;
        }

        return -1;
    }
};

// ------------------------------------------------------------
// Approach 2: Morris Inorder Traversal (O(1) Space)
// ------------------------------------------------------------
class SolutionMorris {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;

        while (root) {
            if (!root->left) {
                if (--k == 0)
                    ans = root->val;

                root = root->right;
            } else {
                TreeNode* pred = root->left;

                while (pred->right && pred->right != root)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = nullptr;

                    if (--k == 0)
                        ans = root->val;

                    root = root->right;
                }
            }
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    SolutionStack s1;
    cout << s1.kthSmallest(root, 1) << "\n";

    SolutionMorris s2;
    cout << s2.kthSmallest(root, 1) << "\n";

    return 0;
}