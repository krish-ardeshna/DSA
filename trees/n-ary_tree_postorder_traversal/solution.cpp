#include <bits/stdc++.h>
using namespace std;

// Problem: N-ary Tree Postorder Traversal
// Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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

class SolutionDFS {
public:
    vector<int> ans;

    void dfs(Node* root) {
        if (!root)
            return;

        for (Node* child : root->children)
            dfs(child);

        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative DFS (Stack + Reverse)
// ------------------------------------------------------------

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root)
            return {};

        vector<int> ans;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();

            ans.push_back(node->val);

            for (Node* child : node->children)
                st.push(child);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    cout << "This problem uses LeetCode's custom structure/API for testing." << endl;
    return 0;
}