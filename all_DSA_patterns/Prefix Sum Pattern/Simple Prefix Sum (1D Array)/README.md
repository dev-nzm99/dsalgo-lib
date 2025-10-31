# Prefix Sum Pattern: Simple 1D Array

🟦 **PATTERN OVERVIEW**  
Imagine you’re keeping track of the daily rainfall for a month. Instead of adding the rain for each day every time you want the total for a week, you precompute cumulative totals. This is the essence of the **Prefix Sum** pattern.

A **prefix sum array** stores cumulative sums of elements up to each index. It allows you to efficiently calculate the sum of any subarray in **O(1) time** after an initial **O(n) preprocessing** step.

**Use Cases:**  
- Subarray sum queries  
- Range sum problems  
- Frequency calculations in arrays  
- Efficient calculation of cumulative values  

---

🟦 **CORE CONCEPTS**  

1. **Definition:**  
For an array `arr` of length `n`, the prefix sum array `prefix` is defined as:  
  prefix[i] = arr[0] + arr[1] + ... + arr[i]


2. **Why Use Prefix Sum?**  
- Instead of summing elements repeatedly, you precompute totals.  
- After precomputation, subarray sums can be computed in **O(1) time**.

3. **Subarray Sum Formula:**  
For any range `[l, r]` (0-indexed):  
sum(l, r) = prefix[r] - prefix[l-1] (if l > 0)
sum(0, r) = prefix[r] (if l = 0)



4. **Time & Space Complexity:**  
- Preprocessing: O(n)  
- Query: O(1)  
- Space: O(n) for the prefix array  

---

🟦 **IMPLEMENTATION APPROACH**  

**Step-by-Step:**  
1. Initialize prefix array of size `n`.  
2. Set `prefix[0] = arr[0]`.  
3. Iterate from index `1` to `n-1`:  
4. To get sum from `l` to `r`, use the formula above.  


---

🟦 **PRACTICE PROBLEMS**  

1. **Range Sum Query - Immutable** – Implement prefix sum for range queries.  
   [LeetCode Link](https://leetcode.com/problems/range-sum-query-immutable/)  

2. **Maximum Subarray Sum** – Use prefix sum to find maximum subarray efficiently.  
   [LeetCode Link](https://leetcode.com/problems/maximum-subarray/)  

3. **Subarray Sum Equals K** – Count subarrays with a given sum using prefix sum + hashmap.  
   [LeetCode Link](https://leetcode.com/problems/subarray-sum-equals-k/)  

4. **Running Sum of 1d Array** – Compute running totals directly.  
   [LeetCode Link](https://leetcode.com/problems/running-sum-of-1d-array/)  

---

🟦 **TIPS**  
- Prefix sums are excellent for **static arrays** where the array doesn’t change frequently.  
- For **dynamic updates**, consider **Fenwick Trees** or **Segment Trees**.  
- Always handle **edge cases** for `l = 0` to avoid negative indices.  

---

This pattern is a fundamental building block for **efficient subarray queries** and forms the basis for more advanced techniques like **2D prefix sums** and **modular prefix sums**.

