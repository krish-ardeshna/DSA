# Asteroid Collision
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/asteroid-collision/  
Difficulty: Medium  
Pattern: Stack Simulation

## What I understood
Each asteroid moves at the same speed; positive value means moving right, negative means moving left. Two asteroids collide only when a right-moving one is immediately followed (in array order, not necessarily adjacent after prior collisions) by a left-moving one. Smaller (by absolute value) explodes; equal size, both explode; same direction asteroids never collide. Return final surviving asteroid state.

## Example
```
Input
asteroids = [5,10,-5]
Output
[5,10]
```
```
Input
asteroids = [8,-8]
Output
[]
```
```
Input
asteroids = [10,2,-5]
Output
[10]
```

## Idea
Stack naturally models collision sequences — a right-moving asteroid just gets pushed (no immediate collision possible, since collisions can only happen with something already "ahead" moving right when a new left-mover arrives). A left-moving asteroid can potentially collide with everything currently in the stack that's right-moving and smaller, one at a time, working backward until either it survives (stack empty or next top is left-moving, no more collisions possible) or it gets destroyed (meets an equal or larger right-mover).

## Approach: Stack-Based Collision Simulation
- Iterate through asteroids.
- If current asteroid is positive (moving right): simply push it — it can't collide with anything already in the stack (same or opposite direction rules only trigger right-then-left adjacency going forward).
- If current asteroid is negative (moving left): enter a collision loop — pop all right-moving stack elements strictly smaller in absolute value than current asteroid (they get destroyed).
- After the loop: if stack top now equals current asteroid's absolute value, both destroy each other (pop, don't push current). Else if stack is empty or top is negative (no more right-movers to collide with), push current asteroid (it survived).
- Build final answer from stack contents, reversed (since stack naturally holds elements in reverse insertion order).

## Key Observation
The three-way outcome (smaller destroyed via loop, equal destroys both via explicit pop, current survives if stack empty/negative-top) must all be handled distinctly — missing the "equal size" case or the "current survives" case would produce incorrect results. Once a left-mover finishes colliding (or doesn't collide at all), no earlier elements deeper in the stack are ever affected — collisions are purely local to the current front of the stack.

## When to use this
If problem involves:
- Simulating sequential interactions/collisions where only the "most recent surviving" state matters
→ Think **stack-based simulation**, processing left-to-right, using the stack as the current "surviving front" that new elements interact with.

## Edge Cases
- All asteroids moving same direction (no collisions, all survive).
- Asteroid destroying multiple right-movers in a chain.
- Equal-size collision (both destroyed).
- Left-moving asteroid encountering another left-moving asteroid on top of stack (no collision, both survive, pushed).

## Complexity
### Approach
Time: **O(n)** — each asteroid pushed and popped from stack at most once        
Space: **O(n)** — stack storage

where:
- `n` = number of asteroids

## Related Problems
- Remove All Adjacent Duplicates in String
- Basic Calculator
- Daily Temperatures
- Validate Stack Sequences