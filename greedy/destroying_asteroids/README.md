# Destroying Asteroids

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/destroying-asteroids/  
Difficulty: Medium  
Pattern: Greedy

## What I understood
We start with an initial mass.

An asteroid can only be destroyed if:
currentMass >= asteroidMass

After destroying it, its mass gets added to our current mass.

The goal is to determine whether all asteroids can be destroyed.

## Idea
Destroy smaller asteroids first.

Every asteroid increases our mass, making it easier to destroy larger asteroids later.

Sorting ensures we always face the easiest asteroid available.

## Approach
- Sort the asteroids in ascending order
- Maintain current mass
- Traverse asteroids:
  - if current mass is smaller than asteroid mass → return false
  - otherwise destroy it and add its mass
- If all asteroids are processed → return true

## Key Observation
Destroying a larger asteroid early never helps.

The safest strategy is to grow gradually by consuming the smallest available asteroids first.

## When to use this
If the problem involves:
- making choices in order
- growing resources over time
- maximizing future options

→ think greedy after sorting

## Edge Cases
- Only one asteroid
- Initial mass already larger than all asteroids
- Very large total mass (use long long)

## Complexity
Time: O(n log n)
- Sorting dominates

Space: O(1)
- Ignoring sorting space

## Related Problems
- Maximum Units on a Truck
- Assign Cookies
- Boats to Save People