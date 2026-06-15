#include <bits/stdc++.h>
using namespace std;

// Problem: Delete the Middle Node of a Linked List
// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Difficulty: Medium
// Pattern: Linked List / Fast & Slow Pointer

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------------------------------------------------------
// Approach: Fast and Slow Pointer
// ------------------------------------------------------------

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution s;

    head = s.deleteMiddle(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";

    return 0;
}