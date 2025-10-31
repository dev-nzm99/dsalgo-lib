# 2D Prefix Sum Pattern

## 1. Pattern Overview

Imagine you are looking at a grid of numbers, like a chessboard, and you want to quickly calculate the sum of numbers in any rectangular section of the board. Instead of summing each element in that section every time, you precompute cumulative sums for each cell based on the top-left corner to that cell. This is the essence of the 2D Prefix Sum pattern.

The 2D Prefix Sum pattern allows you to answer sum queries for any submatrix in O(1) time after O(n*m) preprocessing, where n and m are the dimensions of the matrix.

You'll often use this pattern when:

* Calculating the sum of elements in a submatrix multiple times.
* Handling multiple queries on a grid efficiently.
* Optimizing problems on matrices where repeated range sums are needed.

---

## 2. Core Concepts

### How It Works

* **2D Prefix Sum Array:** Create a matrix `prefix` where `prefix[i][j]` stores the sum of elements from `(0,0)` to `(i,j)`.
* **Querying a Submatrix:** Sum of submatrix from `(r1,c1)` to `(r2,c2)` can be calculated as:
  `sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1]`
* **Edge Cases:** Adjust for boundaries when `r1` or `c1` is 0.

### Why 2D Prefix Sum?

* Avoid repeated summation for each query.
* Transform O(n*m) sum queries into O(1) after preprocessing.
* Saves time in problems with multiple rectangular queries.

### Step-by-Step Thinking

1. Initialize prefix sum matrix with first element.
2. Loop through the matrix and fill prefix sum:

   ```python
   prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
   ```
3. To get sum of any submatrix [(r1,c1),(r2,c2)]:

   ```python
   sum_submatrix = prefix[r2][c2] - (prefix[r1-1][c2] if r1>0 else 0) - (prefix[r2][c1-1] if c1>0 else 0) + (prefix[r1-1][c1-1] if r1>0 and c1>0 else 0)
   ```

### Complexity

* **Time Complexity:**

  * Preprocessing: O(n*m)
  * Each query: O(1)
* **Space Complexity:** O(n*m) — for storing prefix sums.

---

## 3. Implementation Approach

### Step-by-Step Strategy

1. **Build 2D Prefix Sum Matrix:**

   ```python
   for i in range(rows):
       for j in range(cols):
           prefix[i][j] = mat[i][j] + (prefix[i-1][j] if i>0 else 0) + (prefix[i][j-1] if j>0 else 0) - (prefix[i-1][j-1] if i>0 and j>0 else 0)
   ```
2. **Query Sum of Submatrix [(r1,c1),(r2,c2)]:**

   ```python
   sum_submatrix = prefix[r2][c2] - (prefix[r1-1][c2] if r1>0 else 0) - (prefix[r2][c1-1] if c1>0 else 0) + (prefix[r1-1][c1-1] if r1>0 and c1>0 else 0)
   ```
3. **Handle Edge Cases:**

   * Empty matrix: return 0.
   * Single element: prefix sum is the element itself.

### Variants

* **Dynamic Matrix Updates:** Some problems allow modifying elements and still querying efficiently (can use Binary Indexed Tree / Segment Tree for 2D).
* **Modulo Prefix Sum:** Useful for submatrix sum modulo k problems.

---

## 🧩 PRACTICE PROBLEMS

1. **Matrix Block Sum**

   * [LeetCode Link](https://leetcode.com/problems/matrix-block-sum/)

2. **Range Sum Query 2D - Immutable**

   * [LeetCode Link](https://leetcode.com/problems/range-sum-query-2d-immutable/)

3. **Maximum Sum of Rectangle No Larger Than K**

   * [LeetCode Link](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)

4. **Submatrix Sum Queries**

   * [LeetCode Link](https://leetcode.com/problems/submatrix-sum-queries/)

---

By practicing these problems, you'll master the 2D Prefix Sum pattern and efficiently handle submatrix sum queries in grids.
