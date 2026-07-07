#include <bits/stdc++.h>
using namespace std;

// Problem: Insertion Sort List
// Link: https://leetcode.com/problems/insertion-sort-list/
// Difficulty: Medium
// Pattern: Linked List / Sorting

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------------------------------------------------------
// Approach 1: Store Values and Sort
// ------------------------------------------------------------

class SolutionBruteForce {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }

    ListNode* insertionSortList(ListNode* head) {

        vector<int> data;
        ListNode* curr = head;

        while (curr != nullptr) {
            data.push_back(curr->val);
            curr = curr->next;
        }

        sort(data.begin(), data.end(), cmp);
        curr = head;

        while (curr != nullptr) {
            curr->val = data.back();
            data.pop_back();

            curr = curr->next;
        }
        return head;
    }
};

// ------------------------------------------------------------
// Approach 2: Insertion Sort on Linked List
// ------------------------------------------------------------

class SolutionOptimal {
public:
    ListNode* insertionSortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next;
            ListNode* prev = &dummy;

            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {

                prev = prev->next;
            }

            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }
        return dummy.next;
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
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    SolutionOptimal s;
    head = s.insertionSortList(head);

    printList(head);
    return 0;
}