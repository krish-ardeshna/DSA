#include <bits/stdc++.h>
using namespace std;

// Problem: Path Sum
// Link: https://leetcode.com/problems/path-sum/
// Difficulty: Easy
// Pattern: Tree, DFS, Recursion

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ------------------------------------------------------------
// Approach 1: Running Sum
// ------------------------------------------------------------

class SolutionRunningSum {
public:
    bool checkSum(TreeNode* root, int currSum, int targetSum) {
        if(root == nullptr) return false;

        currSum += root->val;

        if(root->left == nullptr && root->right == nullptr) {
            return currSum == targetSum;
        }

        return checkSum(root->left, currSum, targetSum) ||
               checkSum(root->right, currSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkSum(root, 0, targetSum);
    }
};

// ------------------------------------------------------------
// Approach 2: Remaining Sum
// ------------------------------------------------------------

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }

        if(root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        int remainingSum = targetSum - root->val;

        return hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution s;
    cout << boolalpha << s.hasPathSum(root, targetSum);

    return 0;
}