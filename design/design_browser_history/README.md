# Design Browser History

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/design-browser-history/  
Difficulty: Medium  
Pattern: Design

## What I understood
We need to design a browser history system that supports:

- visiting a new page
- moving back
- moving forward

Visiting a new page after going back should remove all forward history.

## Idea
Store all visited pages in a vector.

Maintain an index pointing to the current page.

When visiting a new page:
- remove all pages after the current index
- append the new page
- move the current index forward

For back and forward operations:
- simply update the current index within valid bounds.

## Approach
- Store history in a vector
- Maintain the current page index
- On visit:
  - erase forward history using resize()
  - add the new page
- On back:
  - move the index left
- On forward:
  - move the index right
- Return the current page

## Key Observation
The browser history behaves like an array with a movable pointer.

Whenever a new page is visited, all forward pages become invalid and can be discarded.

## When to use this
If the problem involves:
- browser navigation
- undo and redo operations
- maintaining history
- cursor movement

→ think vector with a current pointer

## Edge Cases
- Back from the first page
- Forward from the latest page
- Visiting a page after moving back
- Large number of operations

## Complexity
Visit: O(1) amortized  
Back: O(1)  
Forward: O(1)  

Space: O(n)

## Related Problems
- Design Twitter
- Design Circular Queue
- LRU Cache
- Min Stack