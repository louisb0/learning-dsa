# two_crystal_balls

Given two crystal balls that will break if dropped from a high enough distance, determine the exact spot in which it will break in the most optimized way.

In a less abstract sense; you've got two glass balls. You're on top of a 20 story building. The strength of the glass is random and unknown. It could drop after 20 stories, 1 story, etc. If you guess a floor too far, your ball will smash and you'll be left with one.

---

### Converting to a computable problem

The first step with solving any problem programatically; model it in some structure which we can interact with via code. So far, we have 'access to' arrays, linear search, and binary search.

``[f, f, f, f, f, t, t, t, t, t] <=> [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]``

We can frame it as an array, where, at the sixth floor, our ball will break. We're essentially trying to find the point where we go from `0`'s to `1`'s. 

### Applying binary search

If we were to try a binary search approach;

* We take the midpoint, floor 5 (index 4). We drop the ball, and it breaks (our worse case). 
* The only possible way to now find the exact breaking point is to drop one floor at a time down to the floor we dropped
    * e.g. breaks after 5 floors; drop one floor, drop two floors, drop 3 floors - breaks, exact point is third floor.
* We then have to walk through, at worst, 1/2 of the array (1/2 * N), which gives an O(n) time complexity.

### Defining the nature of the solution

If we just step back from the problem; once we break a ball, we have almost no choice but to linear search (or just drop a floor at a time) through the rest. Otherwise, we don't have a working algorithm. So, the idea behind the above approach is partially correct; we find some point, then walk to that point until we reach a 1. Just, the issue with choosing the midpoint is that it clearly scales with input linearly.

## Optimising the solution

A more practical approach than taking the midpoint would be to walk in some constant fraction - e.g. for a 100 floor building, drop every 10 floors. If we break on the 30th, then we can walk from the 21st floor to the 29th (knowing the 20th is safe and the 30th isn't). This gives us a O(1/10 * N) = O(n) complexity. 

But, we can make this non-linear by taking the square root for out step. We drop every sqrt(n) floors - e.g. on 10sqrt(n) we break, so we know it is within 10sqrt(n) - 9sqrt(n) = sqrt(n) floors. We have in a worst case; a linear search space of sqrt(n), and a 'discovery' phase of sqrt(n) drops. This gives us O(2*sqrt(n)) = sqrt(n).
