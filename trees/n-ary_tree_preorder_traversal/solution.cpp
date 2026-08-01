#include <bits/stdc++.h>
using namespace std;

// Problem: N-ary Tree Preorder Traversal
// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Difficulty: Easy
// Pattern: Tree, DFS

#ifndef LEETCODE_SUBMIT
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
#endif

// ------------------------------------------------------------
// Approach 1: Recursive DFS
// ------------------------------------------------------------

class Solution {
public:
    vector<int> ans;

    void dfs(Node* root) {
        if (!root)
            return;

        ans.push_back(root->val);

        for (Node* child : root->children)
            dfs(child);
    }

    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative DFS (Stack)
// ------------------------------------------------------------

class Solution2 {
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return {};

        vector<int> ans;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();

            ans.push_back(node->val);

            for (int i = node->children.size() - 1; i >= 0; i--)
                st.push(node->children[i]);
        }

        return ans;
    }
};

int main() {
    cout << "This problem uses LeetCode's custom structure/API for testing." << endl;
    return 0;
}