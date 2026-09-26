#include <bits/stdc++.h>
using namespace std;

// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Difficulty: Medium
// Pattern: Tree - Recursive Index Range / Iterative Stack

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach 1: Recursive Index Range + Hashmap
// ------------------------------------------------------------
class SolutionRecursive {
public:
    TreeNode* construct(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &inMap) {
        if (ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(preorder[ps]);

        int inRoot = inMap[root->val];
        int leftsize = inRoot - is;

        root->left = construct(preorder, ps + 1, ps + leftsize, inorder, is, inRoot - 1, inMap);
        root->right = construct(preorder, ps + leftsize + 1, pe, inorder, inRoot + 1, ie, inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = construct(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

        return root;
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative Stack-Based
// ------------------------------------------------------------
class SolutionIterative {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        int inIndex = 0;

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = st.top();

            if (node->val != inorder[inIndex]) {
                node->left = new TreeNode(preorder[i]);
                st.push(node->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[inIndex]) {
                    node = st.top();
                    st.pop();
                    inIndex++;
                }

                node->right = new TreeNode(preorder[i]);
                st.push(node->right);
            }
        }

        return root;
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    SolutionRecursive s1;
    TreeNode* r1 = s1.buildTree(preorder, inorder);
    cout << r1->val << "\n";

    SolutionIterative s2;
    TreeNode* r2 = s2.buildTree(preorder, inorder);
    cout << r2->val << "\n";

    return 0;
}