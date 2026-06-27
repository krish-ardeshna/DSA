#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Difficulty: Medium
// Pattern: Linked List / Two Pointers

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------------------------------------------------------
// Approach: Two Pointers with Dummy Node
// ------------------------------------------------------------

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution s;
    head = s.removeNthFromEnd(head, n);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << "\n";

    return 0;
}