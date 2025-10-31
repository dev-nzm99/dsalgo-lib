# Modulo Prefix Sum Pattern

## 1. Pattern Overview

Imagine you are distributing candies to children and want to check if some consecutive group of children received a total number of candies divisible by a certain number, say k. Instead of checking all possible groups by summing each, you can keep track of the running sum modulo k. This is the essence of the Modulo Prefix Sum pattern.

The Modulo Prefix Sum pattern is an extension of the prefix sum concept, often used to solve problems involving subarrays whose sum satisfies a modular constraint.

You'll often use this pattern when:

* Checking subarrays or sequences divisible by a number.
* Counting subarrays with certain modulo properties.
* Handling problems related to remainders and divisibility in arrays efficiently.

---

## 2. Core Concepts

### How It Works

* **Prefix Sum Modulo k:** Instead of storing the running sum, store the running sum modulo k.
* **Using Hash Map:** Keep track of the counts of prefix sums modulo k to identify subarrays with desired properties.
* **Key Idea:** If two prefix sums have the same modulo value, the subarray between them is divisible by k.

### Why Modulo Prefix Sum?

* Avoid recomputation for each subarray.
* Transform O(n^2) subarray checks into O(n) using a hash map.
* Efficiently solve divisibility problems on subarrays.

### Step-by-Step Thinking

1. Initialize a hash map with `{0:1}` to account for subarrays starting from index 0.
2. Loop through the array, computing running sum modulo k.
3. If the modulo already exists in the map, it indicates a valid subarray.
4. Update the hash map with the current modulo.

### Complexity

* **Time Complexity:** O(n) — traverse the array once.
* **Space Complexity:** O(k) — for storing modulo counts (or up to O(n) in worst case).

---

## 3. Implementation Approach

### Step-by-Step Strategy

1. **Initialize:**

   ```python
   prefix_mod_count = {0:1}
   running_sum = 0
   count = 0
   ```
2. **Iterate through array:**

   ```python
   for num in arr:
       running_sum += num
       mod = running_sum % k
       if mod in prefix_mod_count:
           count += prefix_mod_count[mod]
       prefix_mod_count[mod] = prefix_mod_count.get(mod, 0) + 1
   ```
3. **Return Result:**

   * Count of subarrays divisible by k.

### Handle Edge Cases

* Negative numbers: Adjust modulo to be non-negative using `(mod + k) % k`.
* Empty array: return 0.
* Single element: check if element % k == 0.

---

## 🧩 PRACTICE PROBLEMS

1. **Subarray Sums Divisible by K**

   * [LeetCode Link](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

2. **Continuous Subarray Sum**

   * [LeetCode Link](https://leetcode.com/problems/continuous-subarray-sum/)

3. **Count Subarrays with Modulo**

   * Use variations of the prefix modulo technique for counting subarrays.

4. **Subarrays with Sum Divisible by K**

   * Practice problems on other platforms using the same concept.

---

By practicing these problems, you'll master the Modulo Prefix Sum pattern and efficiently handle divisibility-related subarray queries.
