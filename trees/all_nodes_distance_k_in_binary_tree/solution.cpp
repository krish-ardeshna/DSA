#include <bits/stdc++.h>
using namespace std;

// Problem: All Nodes Distance K in Binary Tree
// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Difficulty: Medium
// Pattern: Tree - Parent Mapping + BFS (Treat Tree as Undirected Graph)

// ------------------------------------------------------------
// Approach: Build Parent Pointers, BFS from Target Treating Tree as Graph
// ------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_tree) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parent_tree[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_tree[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (curr_level++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;
    vector<int> result = obj.distanceK(root, root->left, 2);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}