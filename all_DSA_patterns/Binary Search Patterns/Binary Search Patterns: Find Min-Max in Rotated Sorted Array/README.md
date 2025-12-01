# Binary Search Patterns: Find Min/Max in Rotated Sorted Array

## 1. Pattern Overview

Imagine you have a bookshelf where all the books are arranged in order, but one day, someone rotates the shelf at a random point. Now, the books still maintain their order, but the starting point has shifted. If you want to find the very first book (the minimum) or the thickest book (the maximum), you can’t just look at the ends anymore—you need a smarter way.

This is where the "Find Min/Max in Rotated Sorted Array" pattern comes in. It’s a specialized use of binary search, designed for arrays that were originally sorted but then rotated at some unknown pivot. You’ll often see this in coding interviews and real-world systems, like searching for a specific log entry in a rotated log file or finding the lowest price in a circularly updated list.

Why is this pattern useful? Because it lets you find the minimum or maximum in O(log n) time, even when the array isn’t perfectly sorted from start to end. Think of it like searching for the first day of the year in a calendar that starts from July instead of January—you don’t have to check every page; you can jump around smartly to find your answer.

You’ll encounter this pattern in problems where:

- The array is sorted but rotated.
- You need to find the smallest/largest element or a specific target.
- Efficiency is key (linear search is too slow).

---

## 2. Core Concepts

Let’s break down the ideas behind this pattern:

### A. What is a Rotated Sorted Array?

Imagine a sorted array: [1, 2, 3, 4, 5, 6, 7].  
If you rotate it at index 3, it becomes [4, 5, 6, 7, 1, 2, 3].  
The order is preserved, but the "start" has shifted.

### B. Why Not Linear Search?

A naive approach would check every element to find the min/max—O(n) time.  
But because the array is mostly sorted, we can use binary search to cut the search space in half each time—O(log n) time.

### C. How Does Binary Search Help?

Normally, binary search works on fully sorted arrays.  
In a rotated array, one half is always sorted. By checking which half is sorted, we can decide where to search next.

Visualize it like flipping through a book:

- If the middle page is in order with the rightmost page, the smallest page must be on the left, or at the middle.
- If not, it’s on the right.

### D. Time and Space Complexity

- Time: O(log n) — Each guess cuts the remaining search in half, like guessing a number between 1 and 100 by always picking the midpoint.
- Space: O(1) — We only need a few pointers (start, end, mid).

### E. Mathematical Foundation

The key is comparing `nums[mid]` to `nums[end]` or `nums[start]` to determine which side is sorted.

- If `nums[mid] > nums[end]`, the minimum is to the right.
- If `nums[mid] < nums[end]`, the minimum is at mid or to the left.

---

## 3. Implementation Approach

Let’s build a mental model for tackling these problems:

### Step 1: Recognize the Pattern

- Is the array sorted but possibly rotated?
- Are you asked to find the minimum, maximum, or a specific value efficiently?

### Step 2: Set Up Binary Search

- Use two pointers: left and right (start and end of the array).
- While `left < right`, calculate `mid = left + (right - left) / 2`.

### Step 3: Decide Which Half to Search

Ask yourself: Is the middle element greater than the rightmost element?

- Yes: The minimum must be to the right of mid (since the rotation point is there).
- No: The minimum is at mid or to the left.

### Step 4: Handle Edge Cases

- No Rotation: If the array is not rotated, the first element is the minimum.
- Duplicates: If elements can repeat (as in "Search in Rotated Sorted Array II"), you may need to adjust your logic to handle equal values.
- Single Element: If the array has only one element, that’s your answer.

### Step 5: Loop Until You Find the Answer

Keep narrowing your search window until `left == right`.  
The minimum (or maximum) will be at this position.

---

### Decision Tree:

- Is `nums[mid] > nums[right]`? Search right half.
- Is `nums[mid] < nums[right]`? Search left half (including mid).
- Are there duplicates? Consider shrinking both ends.

### Example Edge Case:

Array: `[2, 2, 2, 0, 1, 2]`  
Duplicates at both ends—be careful to move pointers inward if `nums[mid] == nums[right]`.
