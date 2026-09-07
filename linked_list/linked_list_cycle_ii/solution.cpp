#include <bits/stdc++.h>
using namespace std;

// Problem: Linked List Cycle II
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Difficulty: Medium
// Pattern: Linked List - Floyd's Cycle Detection (Tortoise and Hare)

// ------------------------------------------------------------
// Approach: Fast/Slow Pointer Meet + Reset One to Head
// ------------------------------------------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }
        return NULL;
    }
};

int main() {
    ListNode* n3 = new ListNode(2);
    ListNode* n2 = new ListNode(0);
    ListNode* n1 = new ListNode(4);
    ListNode* head = new ListNode(3);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n1; // cycle back to n1

    Solution obj;
    ListNode* result = obj.detectCycle(head);

    if (result) cout << result->val;
    else cout << "No cycle";

    return 0;
}