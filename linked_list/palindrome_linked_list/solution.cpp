#include <bits/stdc++.h>
using namespace std;

// Problem: Palindrome Linked List
// Link: https://leetcode.com/problems/palindrome-linked-list/
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
// Approach: Find Middle + Reverse Second Half
// ------------------------------------------------------------

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;

        while (slow) {
            ListNode* nextNode = slow->next;
    
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    cout << boolalpha << s.isPalindrome(head) << "\n";

    return 0;
}