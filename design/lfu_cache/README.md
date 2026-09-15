# LFU Cache
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/lfu-cache/  
Difficulty: Hard  
Pattern: Design - Doubly Linked List + Hashmap (Frequency Buckets)

## What I understood
Design a Least Frequently Used (LFU) cache with `get` and `put` operations, both in O(1) average time. On eviction (when capacity is exceeded), remove the least FREQUENTLY used key; if a tie exists, remove the LEAST RECENTLY used among those tied. Every access (`get` or `put` on existing key) increments that key's usage frequency.

## Example
```
Input
["LFUCache","put","put","get","put","get","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
Output
[null,null,null,1,null,-1,3,null,-1,3,4]
```

## Idea
Maintain two hashmaps: `keyMap` (key → Node, for O(1) key lookup) and `freqMap` (frequency → doubly linked list of nodes with that exact frequency, ordered by recency - most recent at front). Track `minFreq` (current lowest frequency present in cache) separately, updated whenever a frequency bucket becomes empty. Every access moves a node from its current frequency bucket to the next frequency's bucket (inserted at front, marking it as most-recently-used within that new frequency tier).

## Approach: Per-Frequency Doubly Linked Lists + Key/Freq Hashmaps
- **Node**: stores key, val, freq, and DLL pointers.
- **DLL** (custom doubly linked list per frequency): supports `insertFront` (O(1) insert as most recent), `remove` (O(1) removal given a node pointer), `removeLast` (O(1) eviction of least recently used within this frequency).
- **`increaseFreq`**: removes node from its old frequency's DLL, updates `minFreq` if that bucket became empty AND was the current minimum, increments node's freq, inserts into new (possibly newly created) frequency's DLL at front.
- **`get(key)`**: if key exists, call `increaseFreq`, return value; else return -1.
- **`put(key, value)`**: if key exists, update value and call `increaseFreq`. Else, if at capacity, evict from `freqMap[minFreq]`'s LRU end (`removeLast`), erase from `keyMap`. Insert new node with freq=1, reset `minFreq = 1` (new node always starts as the least frequent).

## Key Observation
Tracking `minFreq` explicitly (rather than searching for it each time) is what keeps eviction O(1) - since a new node always enters at frequency 1, `minFreq` resets to 1 immediately on every fresh insertion, and only needs updating (increment) when the CURRENT minimum frequency's bucket becomes empty due to a promotion.

## When to use this
If problem involves:
- Cache design requiring O(1) get/put with frequency-based (not just recency-based) eviction policy
→ Think **hashmap of doubly linked lists keyed by frequency** + a hashmap for direct key lookup + explicit `minFreq` tracking, avoiding any O(n) scan for eviction decisions.

## Edge Cases
- Capacity 0 (no items should ever be stored, `put` should no-op immediately).
- Multiple keys with the same frequency (tie-broken by LRU within that frequency's DLL).
- Updating an existing key's value via `put` (still counts as an access, increments frequency).
- Repeated `get` calls on the same key (frequency increments each time, moving between different frequency buckets each time).

## Complexity
### Approach
Time: **O(1)** average for both `get` and `put`         
Space: **O(capacity)** - bounded by cache capacity

where:
- All operations (insert, remove, promote) on the custom DLL are O(1) via direct pointer manipulation

## Related Problems
- LRU Cache
- Design In-Memory File System
- All O`one Data Structure
- Design a Stack With Increment Operation