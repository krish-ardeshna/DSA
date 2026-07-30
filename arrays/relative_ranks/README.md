# Relative Ranks

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/relative-ranks/  
Difficulty: Easy  
Pattern: Sorting

## What I understood
Given the scores of athletes, assign their ranks based on descending score.

- 1st place → **Gold Medal**
- 2nd place → **Silver Medal**
- 3rd place → **Bronze Medal**
- Remaining athletes receive their numeric rank.

## Example

```
Input
score = [5,4,3,2,1]

Output
["Gold Medal","Silver Medal","Bronze Medal","4","5"]
```

## Idea
Sorting the athletes by score gives their ranking order.

Since the output must follow the original order, store each athlete's original index before sorting and place the assigned rank back into the corresponding position.

## Approach: Sorting
- Store each athlete as `(score, originalIndex)`.
- Sort the athletes in descending order of score.
- Assign medals to the top three athletes.
- Assign numeric ranks to the remaining athletes.
- Place each rank at its original index.

## Key Observation
Sorting determines the ranking, while storing the original index allows the final answer to be reconstructed in the input order.

## When to use this
If the problem involves:
- Ranking elements
- Top K ordering
- Restoring original positions after sorting
- Assigning labels based on sorted order

→ Think **Sorting + Original Index**.

## Edge Cases
- Only one athlete.
- Exactly two athletes.
- Exactly three athletes.
- Large number of athletes.

## Complexity

### Approach
Time: **O(n log n)**

Space: **O(n)**

where:
- `n` = number of athletes

## Related Problems
- Sort the People
- Rank Transform of an Array
- Height Checker