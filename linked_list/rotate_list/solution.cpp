#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate List
// Link: https://leetcode.com/problems/rotate-list/
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
// Approach: Circular Linked List
// ------------------------------------------------------------

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int length = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        k %= length;
        if (k == 0) {
            return head;
        }

        tail->next = head;

        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;

        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
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

    int k = 2;

    Solution s;
    head = s.rotateRight(head, k);

    printList(head);
    return 0;
}