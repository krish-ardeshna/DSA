#include <bits/stdc++.h>
using namespace std;

// Problem: Intersection of Two Linked Lists
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Difficulty: Easy
// Pattern: Linked List - Two Pointer (Switch Heads)

// ------------------------------------------------------------
// Approach: Two Pointer, Switch to Other List's Head on Reaching End
// ------------------------------------------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            temp1 = (temp1 == nullptr) ? headB : temp1->next;
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }

        return temp1;
    }
};

int main() {
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution obj;
    ListNode* result = obj.getIntersectionNode(headA, headB);

    if (result) cout << result->val;
    else cout << "No intersection";

    return 0;
}