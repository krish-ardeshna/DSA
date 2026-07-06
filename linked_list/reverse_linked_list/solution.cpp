#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Easy
// Pattern: Linked List

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------------------------------------------------------
// Approach: Iterative Pointer Reversal
// ------------------------------------------------------------

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    head = s.reverseList(head);

    printList(head);
    return 0;
}