#include <bits/stdc++.h>
using namespace std;

// Problem: Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/
// Difficulty: Easy
// Pattern: Linked List / Fast & Slow Pointer

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// ------------------------------------------------------------
// Approach 1: Hash Set
// ------------------------------------------------------------

class SolutionHashing {
public:
    bool hasCycle(ListNode* head) {

        unordered_set<ListNode*> visited;

        while (head != nullptr) {
            if (visited.count(head)) {
                return true;
            }

            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};

// ------------------------------------------------------------
// Approach 2: Floyd's Cycle Detection
// ------------------------------------------------------------

class SolutionOptimal {
public:
    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: tail -> node with value 2
    head->next->next->next->next = head->next;
    SolutionOptimal s;

    cout << boolalpha << s.hasCycle(head) << "\n";
    return 0;
}