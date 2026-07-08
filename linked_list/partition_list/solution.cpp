#include <bits/stdc++.h>
using namespace std;

// Problem: Partition List
// Link: https://leetcode.com/problems/partition-list/
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
// Approach 1: Store Values and Rewrite List
// ------------------------------------------------------------

class SolutionBruteForce {
public:
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr) {
            return head;
        }

        vector<int> values;

        ListNode* curr = head;

        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> reordered;

        for (int num : values) {
            if (num < x) {
                reordered.push_back(num);
            }
        }

        for (int num : values) {
            if (num >= x) {
                reordered.push_back(num);
            }
        }

        curr = head;

        for (int num : reordered) {
            curr->val = num;
            curr = curr->next;
        }

        return head;
    }
};

// ------------------------------------------------------------
// Approach 2: Two Dummy Lists
// ------------------------------------------------------------

class SolutionOptimal {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode beforeDummy(0);
        ListNode afterDummy(0);

        ListNode* before = &beforeDummy;
        ListNode* after = &afterDummy;

        while (head != nullptr) {

            if (head->val < x) {
                before->next = head;
                before = before->next;
            }
            else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        after->next = nullptr;
        before->next = afterDummy.next;

        return beforeDummy.next;
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
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    SolutionOptimal s;
    head = s.partition(head, x);

    printList(head);
    return 0;
}