#include <bits/stdc++.h>
using namespace std;

// Problem: Delete Node in a Linked List
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Difficulty: Medium
// Pattern: Linked List - Value Copy Trick

// ------------------------------------------------------------
// Approach: Copy Next Node's Value, Skip Next Node
// ------------------------------------------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    ListNode* a = new ListNode(4);
    ListNode* b = new ListNode(5);
    ListNode* c = new ListNode(1);
    ListNode* d = new ListNode(9);
    a->next = b;
    b->next = c;
    c->next = d;

    Solution obj;
    obj.deleteNode(b);

    for (ListNode* cur = a; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }

    return 0;
}               