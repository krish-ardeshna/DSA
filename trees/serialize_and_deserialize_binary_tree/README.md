# Serialize and Deserialize Binary Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/  
Difficulty: Hard  
Pattern: Tree - BFS Level Order with Null Markers

## What I understood
Design an algorithm to serialize a binary tree into a string, and deserialize that string back into the original tree structure. No constraint on the specific serialization format, as long as encode/decode are consistent and correctly reconstruct the tree.

## Example
```
Input
root = [1,2,3,null,null,4,5]
Output
Serialized string, then deserialized back into the identical tree structure
```

## Idea
Standard BFS naturally visits nodes level by level. During serialization, explicitly record NULL children using a placeholder marker (`"#"`) instead of skipping them - this preserves the tree's exact shape information (which children are missing), essential for correct reconstruction. During deserialization, reverse the process: read values in the same BFS order, using a queue to track parent nodes still needing their children attached.

## Approach: BFS Serialize with "#" Null Markers, BFS Deserialize Rebuilding Level by Level
- **`serialize`**: BFS from root, for each dequeued node (including NULL), append value (or `"#"` for null) followed by a comma. Only push children (even if null) for non-null nodes - this correctly bounds the traversal without infinite null-child expansion.
- **`deserialize`**: parse the comma-separated string token by token (via `stringstream` + `getline`). Create root from first token, push onto queue. For each dequeued node, read its NEXT TWO tokens (left and right child values), creating and attaching child nodes (or setting null) accordingly, pushing newly created non-null children onto the queue for their own children to be processed later.

## Key Observation
Explicitly serializing NULL markers (rather than just omitting them) is essential - without them, the deserializer couldn't distinguish "this node has no left child" from "this position doesn't need any more input," especially since binary trees aren't necessarily complete/balanced.

## When to use this
If problem involves:
- Converting a tree structure to/from a flat string representation, preserving exact shape
→ Think **BFS with explicit null markers**, ensuring deserialization can reconstruct exactly which children exist at every node without ambiguity.

## Edge Cases
- Empty tree (`root == nullptr`, serializes to empty string, deserializes back to nullptr).
- Single node tree.
- Skewed tree (many consecutive null markers on one side).
- Tree with negative values (ensure `stoi` handles negative number parsing correctly, which it does by default).

## Complexity
### Approach
Time: **O(n)** for both serialize and deserialize       
Space: **O(n)** - queue storage, output string storage

where:
- `n` = number of nodes

## Related Problems
- Encode and Decode Strings
- Construct Binary Tree from Preorder and Inorder Traversal
- Copy List with Random Pointer
- Design a Binary Tree