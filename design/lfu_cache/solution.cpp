#include <bits/stdc++.h>
using namespace std;

// Problem: LFU Cache
// Link: https://leetcode.com/problems/lfu-cache/
// Difficulty: Hard
// Pattern: Design - Doubly Linked List + Hashmap (Frequency Buckets)

// ------------------------------------------------------------
// Approach: Per-Frequency Doubly Linked Lists + Key/Freq Hashmaps
// ------------------------------------------------------------
class LFUCache {
    struct Node {
        int key;
        int val;
        int freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    struct DLL {
        Node* head;
        Node* tail;
        int size;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void insertFront(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            size--;
        }

        Node* removeLast() {
            if (size == 0)
                return nullptr;

            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

    int capacity;
    int minFreq;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void increaseFreq(Node* node) {
        int oldFreq = node->freq;

        freqMap[oldFreq]->remove(node);

        if (oldFreq == minFreq && freqMap[oldFreq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqMap.find(node->freq) == freqMap.end())
            freqMap[node->freq] = new DLL();

        freqMap[node->freq]->insertFront(node);
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];

        increaseFreq(node);

        return node->val;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];

            node->val = value;

            increaseFreq(node);

            return;
        }

        if (keyMap.size() == capacity) {
            Node* lru = freqMap[minFreq]->removeLast();

            keyMap.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        keyMap[key] = node;

        if (freqMap.find(1) == freqMap.end())
            freqMap[1] = new DLL();

        freqMap[1]->insertFront(node);

        minFreq = 1;
    }
};

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n";
    cache.put(3, 3);
    cout << cache.get(2) << "\n";
    cout << cache.get(3) << "\n";
    return 0;
}