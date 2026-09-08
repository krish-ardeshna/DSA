#include <bits/stdc++.h>
using namespace std;

// Problem: Copy List with Random Pointer
// Link: https://leetcode.com/problems/copy-list-with-random-pointer/
// Difficulty: Medium
// Pattern: Linked List - Interweaving Clone (O(1) Space)

// ------------------------------------------------------------
// Approach: Interweave Copies, Wire Random Pointers, Detach
// ------------------------------------------------------------
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;

        while (temp != nullptr) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);

            temp->next = copy;
            copy->next = nextElement;

            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;

        while (temp != nullptr) {
            Node* copyNode = temp->next;

            if (temp->random) {
                copyNode->random = temp->random->next;
            }
            else {
                copyNode->random = nullptr;
            }

            temp = temp->next->next;
        }
    }

    Node* getDeepCopy(Node* head) {
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopy(head);
    }
};

int main() {
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution obj;
    Node* result = obj.copyRandomList(n1);

    for (Node* cur = result; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }

    return 0;
}