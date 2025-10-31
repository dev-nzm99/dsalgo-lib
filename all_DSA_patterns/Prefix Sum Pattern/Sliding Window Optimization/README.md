# Sliding Window Optimization: Prefix Sum Sub-Pattern

## 1. Pattern Overview

The Sliding Window Optimization with Prefix Sum is a combination of two powerful techniques: prefix sums and sliding windows. It allows you to efficiently calculate sums over subarrays while dynamically adjusting window sizes, without recomputing sums repeatedly.

Imagine you want the sum of every contiguous subarray of size k in an array. Instead of recalculating the sum for each window, you can preprocess a prefix sum array and then use sliding window logic to efficiently get sums in O(1) per window.

You'll often use this pattern when:

* You need to handle sum queries on a sliding window efficiently.
* You want to optimize solutions that would otherwise require nested loops.
* Subarrays of fixed or variable length need sum computation.

---

## 2. Core Concepts

### How It Works

1. **Prefix Sum Array:** Precompute cumulative sums to allow O(1) sum queries for any subarray.
2. **Sliding Window:** Use two pointers to define the start and end of a window.
3. **Window Sum Calculation:** Instead of recalculating the sum each time, use prefix sums to compute it quickly: `sum(l, r) = prefix[r] - prefix[l-1]`.

### Why This Pattern?

* Avoid repeated summation inside a loop.
* Combine the efficiency of prefix sums with dynamic window adjustments.
* Optimize O(n*k) solutions to O(n) using prefix sum preprocessing.

### Complexity

* **Time Complexity:**

  * Prefix sum preprocessing: O(n)
  * Sliding window queries: O(n) for all windows
* **Space Complexity:** O(n) for the prefix sum array.

---

## 3. Implementation Approach

### Step-by-Step Strategy

1. **Compute Prefix Sum:**

   ```python
   prefix[0] = arr[0]
   for i in range(1, n):
       prefix[i] = prefix[i-1] + arr[i]
   ```
2. **Sliding Window Sums:**

   ```python
   for i in range(n - k + 1):  # for window of size k
       window_sum = prefix[i + k - 1] - (prefix[i-1] if i > 0 else 0)
       # Use window_sum as needed
   ```
3. **Variable Window Sizes:** Adjust `i` and `j` pointers dynamically, always using prefix sum to compute current window sum.

### Edge Cases

* Empty array: return 0.
* Window size larger than array: handle separately.
* Single element window: use the element itself.

### Variants

* **Maximum/Minimum Sum Window:** Use prefix sums for fixed-length windows.
* **Modulo Prefix Sum Window:** For subarrays satisfying divisibility constraints.
* **2D Prefix Sum + Sliding Window:** For submatrix sum queries.
* **Dynamic Window Adjustments:** Combine with conditions like sum <= k or sum >= k.

---

## 🧩 PRACTICE PROBLEMS

1. **Maximum Average Subarray I**

   * [LeetCode Link](https://leetcode.com/problems/maximum-average-subarray-i/)

2. **Maximum Sum Circular Subarray**

   * [LeetCode Link](https://leetcode.com/problems/maximum-sum-circular-subarray/)

3. **Subarray Sums Divisible by K (Sliding Window Variant)**

   * [LeetCode Link](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

4. **Minimum Size Subarray Sum**

   * [LeetCode Link](https://leetcode.com/problems/minimum-size-subarray-sum/)

---

By combining prefix sums with sliding window logic, you can optimize subarray sum computations and handle dynamic windows efficiently.
