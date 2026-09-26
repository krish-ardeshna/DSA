#include <bits/stdc++.h>
using namespace std;

// Problem: Construct Binary Tree from Inorder and Postorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* construct(vector<int>& inorder, int is, int ie,
                        vector<int>& postorder, int ps, int pe,
                        unordered_map<int, int> &inMap)
    {
        if (ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = inMap[root->val];
        int leftsize = inRoot - is;

        root->left = construct(inorder, is, inRoot - 1, postorder, ps, ps + leftsize - 1, inMap);
        root->right = construct(inorder, inRoot + 1, ie, postorder, ps + leftsize, pe - 1, inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = construct(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);

        return root;
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative Stack-Based
// ------------------------------------------------------------
class SolutionIterative {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(postorder.back());
        stack<TreeNode*> st;
        st.push(root);

        int inIndex = inorder.size() - 1;

        for (int i = postorder.size() - 2; i >= 0; i--) {
            TreeNode* node = st.top();

            if (node->val != inorder[inIndex]) {
                node->right = new TreeNode(postorder[i]);
                st.push(node->right);
            } else {
                while (!st.empty() && st.top()->val == inorder[inIndex]) {
                    node = st.top();
                    st.pop();
                    inIndex--;
                }

                node->left = new TreeNode(postorder[i]);
                st.push(node->left);
            }
        }

        return root;
    }
};

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    SolutionRecursive s1;
    TreeNode* r1 = s1.buildTree(inorder, postorder);
    cout << r1->val << "\n";

    SolutionIterative s2;
    TreeNode* r2 = s2.buildTree(inorder, postorder);
    cout << r2->val << "\n";

    return 0;
}