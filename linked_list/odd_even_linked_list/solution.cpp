#include <bits/stdc++.h>
using namespace std;

// Problem: Odd Even Linked List
// Link: https://leetcode.com/problems/odd-even-linked-list/
// Difficulty: Medium
// Pattern: Linked List - Two Pointer (Interleaved Rewiring)

// ------------------------------------------------------------
// Approach: Separate Odd/Even Chains, Reconnect
// ------------------------------------------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
    }
};

int main() {
    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* head = new ListNode(1, n2);

    Solution obj;
    ListNode* result = obj.oddEvenList(head);

    for (ListNode* cur = result; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }

    return 0;
}