#include <bits/stdc++.h>
using namespace std;

// Problem: Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists/
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
// Approach 1: Recursive Merge
// ------------------------------------------------------------

class SolutionRecursive {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }

        if (!list2) {
            return list1;
        }

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};

// ------------------------------------------------------------
// Approach 2: Iterative Merge using Dummy Node
// ------------------------------------------------------------

class SolutionOptimal {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        return dummy->next;
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
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    SolutionOptimal s;
    ListNode* merged = s.mergeTwoLists(list1, list2);

    printList(merged);
    return 0;
}