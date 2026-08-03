#include <bits/stdc++.h>
using namespace std;

// Problem: Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree/
// Difficulty: Easy
// Pattern: Tree - DFS (Recursion) / BFS (Queue)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach 1: Recursive Mirror Check
// ------------------------------------------------------------
class SolutionRecursive {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr)
            return left == right;

        return left->val == right->val && isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};

// ------------------------------------------------------------
// Approach 2: BFS (Queue) — mirrored pair comparison
// ------------------------------------------------------------
class SolutionBFS {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();

            TreeNode* right = q.front();
            q.pop();

            if (!left && !right) continue;
            if (!left || !right) return false;

            if (left->val != right->val) return false;

            q.push(left->left);
            q.push(right->right);

            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    SolutionRecursive s1;
    cout << s1.isSymmetric(root) << "\n";

    SolutionBFS s2;
    cout << s2.isSymmetric(root) << "\n";

    return 0;
}