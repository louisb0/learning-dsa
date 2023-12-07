# bubble_sort

A sorted array simply fits, or is defined by, `x_i <= x_{i+1}`. 

Bubble sort works to just fill this definition. For each element, we check the opposite (`x_i > x_{i+1}`). If we find this case, we repair it by switching the two elements, meaning that `x_i <= x_{i+1}` is true again.

Now, this requires multiple passes. For example, applying that same logic on each pass;

1. [2, 1, 0, 0, 0]
2. [1, 0, 0, 0, 2]
3. [0, 0, 0, 1, 2]

We essentially take the first element, check that it fits the definition. If not, make it fit the definition for this specific index. Repeat. This causes elements to 'bubble' to the top of the list.

### Complexity

Given that in one pass, we will bubble the largest number to the last index, we no longer have to check the last index on the next pass. So, for each element, we check;

1. 0 <-> N
2. 0 <-> N - 1
3. ...
4. 0 <-> N - (N - 1)

In reality this is more like, for an element of size 5, 5 + 4 + 3 + 2 + 1 (N + (N-1) + ... + (N-(N-1)). This is given by the formula `n(n+1)/2`, which simplifies to an `O(n^2)` time complexity.

---

**`n(n+1)/2`**:

This is the sum of n natural numbers, i.e. the sum of n positive integers. Why does this work?

Let's say n = 10.

> 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10

We can split this into pairs to sum.

1. 1 + 10 = 11
2. 2 + 9 = 11
3. 3 + 8 = 11
4. 4 + 7 = 11
6. 5 + 6 = 11

In general, we get `n/2` pairs of `(n+1)`, `n(n+1)/2`. This doesn't constitute a proof by any means, but it shows the idea.
