# Find the Town Judge

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-town-judge/  
Difficulty: Easy  
Pattern: Graph, Degree Counting

## What I understood
In a town of `n` people:
- The judge trusts nobody.
- Everybody else trusts the judge.
- There is at most one judge.

Return the judge's label if one exists; otherwise return `-1`.

Example:
```
n = 3
trust = [[1,3],[2,3]]
Output = 3
```

## Idea
The judge must satisfy two conditions:
- Trusted by exactly `n - 1` people.
- Trusts nobody.

Each approach checks these conditions more efficiently than the previous one.

## Approach 1: Hash Set + Frequency Map
- Store everyone who trusts someone in a hash set.
- Count how many times each person is trusted.
- Return the person who is not in the hash set and whose trusted count equals `n - 1`.

## Approach 2: In-degree & Out-degree
- Maintain:
  - `indegree` = number of people trusting a person.
  - `outdegree` = number of people a person trusts.
- Return the person with:
  - `indegree == n - 1`
  - `outdegree == 0`

## Approach 3: Single Degree Array (Optimal)
- Maintain one degree array.
- Decrease the degree when a person trusts someone.
- Increase the degree when a person is trusted.
- Return the person whose degree equals `n - 1`.

## Key Observation
Instead of maintaining two arrays, combine both into one:
```
degree = indegree - outdegree
```
Only the judge can have a degree of `n - 1`.

## When to use this
If the problem involves:
- Trust relationships
- In-degree and out-degree
- Identifying a special node
- Graph properties

→ Think **Degree Counting**.

## Edge Cases
- `n = 1`, `trust = []` → Answer is `1`.
- No person satisfies both judge conditions.
- Empty trust list when `n > 1` → Answer is `-1`.
- A person is trusted by everyone but also trusts someone.

## Complexity

### Approach 1
Time: **O(n + m)**  
Space: **O(n)**

### Approach 2
Time: **O(n + m)**  
Space: **O(n)**

### Approach 3
Time: **O(n + m)**  
Space: **O(n)**

where `m` is the number of trust relationships.

## Related Problems
- Find Center of Star Graph
- Find Champion II
- Find the Celebrity