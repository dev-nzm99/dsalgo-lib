# Sliding Window Pattern: Fixed Size (Subarray Calculation)

## 1. Pattern Overview

Imagine you’re looking through a long train, and you want to examine every group of exactly 3 consecutive cars. Instead of walking back to the start each time, you just move one car forward and look at the next group. This is the essence of the Fixed Size Sliding Window pattern.

In programming, this pattern is like using a window of a set size (say, 3 elements) that "slides" over an array or data stream. At each step, you examine only the elements inside the window, perform some calculation (like sum, average, or max), and then move the window one step forward.

### When is this useful?

* To process or analyze every contiguous subarray of a fixed length.
* Examples:

  * Maximum average temperature over any 7-day period.
  * Most frequent word in every 100-word segment of a book.
* Analogy: A moving magnifying glass that always covers 3 words in a sentence. You read those 3, then move the glass one word forward, and repeat.

### Why use it?

* Avoid redundant work. Instead of recalculating everything from scratch for each window, you update your result using just the elements entering and leaving the window. Efficient for large datasets.

---

## 2. Core Concepts

### How does it work?

* **Window:** A subarray of fixed length k that moves from start to end.
* **Sliding:** At each step, "slide" the window by one position—remove the element at the start, add the next element at the end.
* **Efficient Updates:** Update results using only the elements entering and leaving the window.

### Visualization

Array: `[2, 3, 5, 7, 11, 13]`, window size `k = 3`:

* First window: `[2, 3, 5]`
* Slide right: `[3, 5, 7]`
* Slide right: `[5, 7, 11]`
* Slide right: `[7, 11, 13]`

### Why is this efficient?

* **Naive approach:** Sum all k elements for each window → O(n*k)
* **Sliding window:** Subtract leaving element, add new element → O(n)
* Analogy: Reading book page by page vs re-reading the whole book for each page.

### Time and Space Complexity

* **Time:** O(n), each element processed once.
* **Space:** O(1) extra space for simple calculations, O(k) if storing the window.

### Mathematical Foundation

* Overlapping windows share most elements. Reusing previous calculations avoids repetition.

### Practical Connections

* Streaming data (moving averages), signal processing, real-time analytics.

---

## 3. Implementation Approach

### Step-by-Step Thinking

1. **Identify window size (k):** Are you processing groups of k consecutive elements?
2. **Initialize window:** Calculate the result for the first window (sum, max, frequency, etc.).
3. **Slide the window:**

   * Remove element leaving window.
   * Add new element entering window.
   * Update result.
4. **Store or output results:** Keep track of best result or results for each window.

### Decision Tree

* Is the problem asking for all subarrays of size k? → Use sliding window.
* Is the window size fixed? → Fixed-size sliding window.
* Process each window independently? → Sliding window is efficient.

### Edge Cases

* Array shorter than k → handle as invalid or return empty result.
* Window at the end → avoid out-of-bounds.
* Complex calculations (e.g., median) → may need extra data structures.

### Simple Example

Array: `[1, 2, 3, 4, 5]`, window size = 3

* Start sum: 1+2+3 = 6
* Slide: remove 1, add 4 → 2+3+4 = 9
* Slide: remove 2, add 5 → 3+4+5 = 12

### Tips for Implementation

* Use two pointers (`start`, `end`) or a loop index.
* For frequency counts or complex calculations, use a hash table to track elements in the window.

---

## 4. Practice Problems

1. **Maximum Average Subarray I**

   * [LeetCode Link](https://leetcode.com/problems/maximum-average-subarray-i/)

2. **Sliding Window Maximum**

   * [LeetCode Link](https://leetcode.com/problems/sliding-window-maximum/)

3. **Maximum Sum of Subarray of Size K**

   * [GFG Link](https://practice.geeksforgeeks.org/problems/max-of-all-subarrays-of-size-k3101/1)

4. **Longest Subarray with Ones after Replacement**

   * [LeetCode Link](https://leetcode.com/problems/max-consecutive-ones-iii/)

5. **Sum of All Subarrays of Size K**

   * [GFG Link](https://practice.geeksforgeeks.org/problems/sum-of-all-subarrays-of-size-k0531/1)

