#include <bits/stdc++.h>
using namespace std;

// Problem: Clone Graph
// Link: https://leetcode.com/problems/clone-graph/
// Difficulty: Medium
// Pattern: Graph Traversal (DFS, BFS)

// Local testing only — LeetCode provides this Node struct automatically.
// Delete this block before pasting into LeetCode submission box.
#ifndef LEETCODE_SUBMIT
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
#endif

// ------------------------------------------------------------
// Approach 1: Depth-First Search (DFS)
// ------------------------------------------------------------
class SolutionDFS {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        if (mp.count(node))
            return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (Node* neighbor : node->neighbors) {
        
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};

// ------------------------------------------------------------
// Approach 2: Breadth-First Search (BFS)
// ------------------------------------------------------------
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        
        mp[node] = new Node(node->val);
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (Node* neighbor : curr->neighbors) {
                if (!mp.count(neighbor)) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }
        
        return mp[node];
    }
}; 

int main() {
    cout << "This problem uses LeetCode's custom structure/API for testing." << endl;
    return 0;
}