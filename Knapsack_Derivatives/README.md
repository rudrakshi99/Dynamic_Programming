# 0-1 Knapsack Problem 🎒

For each item you are given its weight and its value. You want to maximize the total value of all the items you are going to put in the knapsack such that the total weight of items is less than knapsack’s
capacity. What is this maximum total value?

https://www.spoj.com/problems/KNAPSACK/

To consider all subsets of items, there can be two cases for every item:

(1) the item is included in the optimal subset, (2) not included in the optimal set. Therefore, the maximum value that can be obtained from n items is
max of following two values.
1. Maximum value obtained by n-1 items and W weight (excluding
nth item).
2. Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).

If weight of nth item is greater than W, then the nth item cannot be
included and case 1 is the only possibility.

## Solution

If we build the recursion tree, we can clearly see that the property of **overlapping sub-problems** is satisfied. So, we will try to solve it using dynamic programming.

Let us define the dp solution with states i and j as

``dp[i,j] --> max value that can be obtained with objects upto index i and knapsack capacity of j``

The most optimal solution to the problem will be dp[N][W] i.e. max value that can be obtained upto index N with max capacity of W.

**Time Complexity** := O(NW)

**Space Complexity** := O(NW)

### Can we do better?
If we observe carefully, we can see that the dp solution with states (i,j) will depend on state (i-1, j) or (i-1, j-wt[i-1]). In either case the solution
for state (i,j) will lie in the **i-1th** row of the memoization table. So at every iteration of the index, we can copy the values of current row and
use only this row for building the solution in next iteration and no other row will be used. Hence, at any iteration we will be using only a
**single** row to build the solution for current row. Hence, we can reduce the space complexity to just **O(W)**.

**Time Complexity:** O(N*W)

**Space Complexity:** O(W)
