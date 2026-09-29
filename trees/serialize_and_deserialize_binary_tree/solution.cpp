#include <bits/stdc++.h>
using namespace std;

// Problem: Serialize and Deserialize Binary Tree
// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Difficulty: Hard
// Pattern: Tree - BFS Level Order with Null Markers

// ------------------------------------------------------------
// Approach: BFS Serialize with "#" Null Markers, BFS Deserialize Rebuilding Level by Level
// ------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if (currNode == NULL) s += "#,";
            else s += to_string(currNode->val) + ',';

            if (currNode != nullptr) {
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                node->left = nullptr;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#") {
                node->right = nullptr;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;
    string data = ser.serialize(root);
    cout << data << "\n";

    TreeNode* ans = deser.deserialize(data);
    cout << ans->val;

    return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));