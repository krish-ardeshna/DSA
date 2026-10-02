#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Search Tree Iterator
// Link: https://leetcode.com/problems/binary-search-tree-iterator/
// Difficulty: Medium
// Pattern: Design - Controlled Inorder Traversal (Stack-Based Lazy Expansion)

// ------------------------------------------------------------
// Approach: Stack of Left Spine, Expand Right Subtree Lazily on next()
// ------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }

    void pushAll(TreeNode* node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator obj(root);
    while (obj.hasNext()) {
        cout << obj.next() << " ";
    }

    return 0;
}

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/