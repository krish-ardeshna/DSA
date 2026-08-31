#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
// Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Difficulty: Medium
// Pattern: Linked List - Single Pass (Local Min/Max Detection)

// ------------------------------------------------------------
// Approach: Single Pass, Track First/Previous Critical Point Positions
// ------------------------------------------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, prev = -1;
        int minDist = INT_MAX, maxDist = -1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;
        int pos = 1;

        while (curr->next) {
            ListNode* nextNode = curr->next;

            if ((curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val)) {

                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - prev);
                    maxDist = pos - first;
                }

                prev = pos;
            }

            prevNode = curr;
            curr = nextNode;
            pos++;
        }

        if (minDist == INT_MAX)
            return {-1, -1};

        return {minDist, maxDist};
    }
};

int main() {
    ListNode* n5 = new ListNode(1);
    ListNode* n4 = new ListNode(0, n5);
    ListNode* n3 = new ListNode(5, n4);
    ListNode* n2 = new ListNode(3, n3);
    ListNode* n1 = new ListNode(3, n2);
    ListNode* head = new ListNode(5, n1);

    Solution obj;
    vector<int> result = obj.nodesBetweenCriticalPoints(head);
    cout << result[0] << " " << result[1];
    return 0;
}