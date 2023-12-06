# binary search

A great first question when approaching search; is our input ordered? This gives us a few new approaches, one being binary search.

`search(array, low_index, high_index, target: int)`

> We want to find within the range `[low_index, high_index]`, inclusive of each endpoint. Defining this is important to prevent off-by-one errors. Sometimes it is convention to use `[low_index, high_index)`, i.e. not inclusive of the high index (similar to conventional `for` loops or `range` in Python), which will change how our search works. We'll come back to this.

Since our list is ordered, we can use the midpoint. We do this with `low_index + floor((high_index - low_index) / 2)` (floor v.s. ceil to ensure convergence). We can repeatedly take the midpoint index and compare it to `target`. Let's define the range `[low_index, high_index]`.

1. `target == midpoint`: Finished
2. `target < midpoint`: Then, reduce the search space. Let `high_index = midpoint_index - 1` (as we know `array[midpoint_index] != target`). Repeat.
3. `target > midpoint`: Similarly, let `low_index = midpoint_index + 1` with similar reasoning. Repeat.

It might be clear that this can also be written recursively. Where we 'Repeat', we just rerun binary search with updated low/high indices.

```
search(array, low_index, high_index, target):
    while low_index <= high_index:
        midpoint_index = low_index + floor((high_index - low_index) / 2)
        midpoint_value = array[midpoint_index]

        if target == midpoint_value:
            return midpoint_index
        else if target < midpoint_value:
            high_index = midpoint_index - 1
        else:
            low_index = midpoint_index + 1

    return -1
```

Now with understanding of the algorithm, let's consider the cases with our two different range definitions. It all comes down to how we define our `while` condition.

1. Inclusive `[low_index, high_index]`: 
    * `low_index` and `high_index` are included in the search space.
    * The `while` loop must ensure we continue as long as there is more space to search.
    * Hence, `while low_index <= high_index`.
    * We calculate `{low/high}_index = midpoint +/- 1`, to keep consistent with an inclusive search range.
2. Half-open `[low_index, high_index)`:
    * `high_index` is *not* included in the search space.
    * We then have `while low_index < high_index` as if `low_index == high_index`, then we have no elements to search (as `high_index` is out of the search space), and we stop.
    * We calculate `low_index = midpoint + 1` as this remains inclusive, but `high_index = midpoint`, as we have checked midpoint already and the next iteration assumes we do not include `high_index`, i.e. 'do not look at the midpoint again'. 


## Complexity

Consider we have to take the max number of halves, i.e. we continually halve our search space. 

* `k = 0, search_space = N/2^k` where k is number of halves. N, N/2, N/4, N/8, N/16.
* We want the worst case where our search space is 1 - i.e. not in the array or the last element we checked. We reach here to determine this.
* `N/2^k = 1 <=> N = 2^k <=> log_2(N) = k` - it takes `log_2(N)` halvings (`k`) to reach a search space of 1 (our worst case).

`O(log n)` complexity.