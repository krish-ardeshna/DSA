#include <bits/stdc++.h>
using namespace std;

// Problem: Merge k Sorted Lists
// Link: https://leetcode.com/problems/merge-k-sorted-lists/
// Difficulty: Hard
// Pattern: Linked List / Divide and Conquer

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------------------------------------------------------
// Approach: Divide and Conquer
// ------------------------------------------------------------

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            
            tail = tail->next;
        }

        tail->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) {
            return nullptr;
        }

        int interval = 1;
        int n = lists.size();

        while (interval < n) {
            for (int i = 0; i + interval < n; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
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

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution s;
    ListNode* ans = s.mergeKLists(lists);

    printList(ans);
    return 0;
}