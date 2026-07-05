#include <bits/stdc++.h>
using namespace std;

// Problem: Sort List
// Link: https://leetcode.com/problems/sort-list/
// Difficulty: Medium
// Pattern: Linked List / Merge Sort

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------------------------------------------------------
// Approach 1: Bubble Sort on Linked List
// ------------------------------------------------------------

class SolutionBruteForce {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(-1);
        dummy.next = head;

        bool swapped;

        do {
            swapped = false;

            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr != nullptr && curr->next != nullptr) {
                ListNode* nextNode = curr->next;

                if (curr->val > nextNode->val) {

                    curr->next = nextNode->next;
                    nextNode->next = curr;
                    prev->next = nextNode;

                    prev = nextNode;
                    swapped = true;
                }
                else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        } while (swapped);

        return dummy.next;
    }
};

// ------------------------------------------------------------
// Approach 2: Merge Sort
// ------------------------------------------------------------

class SolutionOptimal {
private:
    ListNode* findMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left != nullptr) {
            tail->next = left;
        }
        else {
            tail->next = right;
        }

        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* middle = findMiddle(head);

        ListNode* secondHalf = middle->next;
        middle->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);

        return mergeTwoLists(left, right);
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
    head = s.sortList(head);

    printList(head);
    return 0;
}