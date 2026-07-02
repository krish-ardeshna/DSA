#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Duplicates from Sorted List II
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Difficulty: Medium
// Pattern: Linked List

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------------------------------------------------------
// Approach: Skip Duplicate Groups
// ------------------------------------------------------------

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->next != nullptr &&
                curr->val == curr->next->val) {

                int duplicate = curr->val;

                while (curr != nullptr &&
                       curr->val == duplicate) {
                        
                    curr = curr->next;
                }
                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution s;
    head = s.deleteDuplicates(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << "\n";
    return 0;
}