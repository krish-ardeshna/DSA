#include <bits/stdc++.h>
using namespace std;

// Problem: Find Mode in Binary Search Tree
// Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Difficulty: Easy
// Pattern: Tree - Hashmap+DFS / Recursive Inorder / Morris Inorder (O(1) space)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach 1: Hashmap + DFS
// ------------------------------------------------------------
class SolutionHashmapDFS {
public:
    unordered_map<int, int> freq;

    void dfs(TreeNode* root) {
        if (!root) return;

        freq[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        int maxFreq = 0;
        for (auto &[val, cnt] : freq) {
            maxFreq = max(maxFreq, cnt);
        }

        vector<int> ans;
        for (auto &[val, cnt] : freq)
            if (cnt == maxFreq)
                ans.push_back(val);

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Recursive Inorder Traversal (O(h) space)
// ------------------------------------------------------------
class SolutionRecursiveInorder {
public:
    vector<int> ans;
    TreeNode* prev = nullptr;
    int cnt = 0;
    int maxCnt = 0;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val == root->val)
            cnt++;
        else
            cnt = 1;

        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans.clear();
            ans.push_back(root->val);
        } else if (cnt == maxCnt) {
            ans.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: Morris Inorder Traversal (O(1) space) - OPTIMAL
// ------------------------------------------------------------
class SolutionMorrisInorder {
public:
    vector<int> ans;
    TreeNode* prev = nullptr;
    int cnt = 0;
    int maxCnt = 0;

    void process(TreeNode* node) {
        if (prev && prev->val == node->val)
            cnt++;
        else
            cnt = 1;

        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans.clear();
            ans.push_back(node->val);
        } else if (cnt == maxCnt) {
            ans.push_back(node->val);
        }

        prev = node;
    }

    vector<int> findMode(TreeNode* root) {
        TreeNode* cur = root;

        while (cur) {
            if (!cur->left) {
                process(cur);
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    process(cur);
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    SolutionHashmapDFS s1;
    vector<int> r1 = s1.findMode(root);
    for (int v : r1) cout << v << " ";
    cout << "\n";

    SolutionRecursiveInorder s2;
    vector<int> r2 = s2.findMode(root);
    for (int v : r2) cout << v << " ";
    cout << "\n";

    SolutionMorrisInorder s3;
    vector<int> r3 = s3.findMode(root);
    for (int v : r3) cout << v << " ";
    cout << "\n";

    return 0;
}