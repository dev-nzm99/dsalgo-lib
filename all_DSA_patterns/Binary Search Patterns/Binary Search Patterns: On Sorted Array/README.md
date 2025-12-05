# Binary Search Patterns: On Sorted Array/List

## 1. Pattern Overview

Imagine you’re searching for a word in a dictionary. Instead of flipping through every single page, you open the book roughly in the middle, see where you are, and decide whether to look in the first half or the second half. This process of repeatedly dividing your search space in half is the essence of binary search.

The "Binary Search on Sorted Array/List" subpattern is all about efficiently finding information in data that’s already sorted. Whether you’re looking for a specific number, the place to insert a new value, or the first occurrence of an error, this pattern helps you zero in on the answer much faster than checking every element one by one.

**When is this pattern useful?**

- Whenever you have a sorted list or array and need to search, insert, or find a boundary (like the first or last occurrence of something).
- Real-world analogy: Looking up a name in a phone book, finding a word in a dictionary, or guessing a number someone is thinking of by asking "higher or lower?"

**Why use it?**

- It’s incredibly efficient: Instead of checking every item (which could take ages for big lists), you cut the problem in half each time. This makes it perfect for large datasets, like searching user IDs, timestamps, or even debugging software versions.

---

## 2. Core Concepts

Let’s break down what makes binary search so powerful and how it works:

### The Step-by-Step Process

- **Sorted Data is Key:** Binary search only works if your data is sorted. Think of trying to find a word in a shuffled dictionary—it just wouldn’t work!
- **Divide and Conquer:** You start with two pointers: `left` at the beginning and `right` at the end of your array.
- **Find the Middle:** Calculate the middle index, usually as `mid = left + (right - left) / 2` to avoid overflow.
- **Compare:** Check if the middle element is what you’re looking for.
  - If it is, you’re done!
  - If your target is smaller, you repeat the process on the left half.
  - If it’s larger, you repeat on the right half.
- **Repeat:** Each time, you halve the number of elements you need to check.

### Visualizing the Process

Imagine a row of lockers numbered 1 to 100, and you’re looking for locker 73. Instead of opening each locker one by one, you start at locker 50. If 73 is higher, you jump to locker 75, then maybe to 62, and so on—always halving your search space.

### Time and Space Complexity

- **Time Complexity:** `O(log n)`. If you have 1,000,000 items, you only need about 20 steps to find your answer!
- **Space Complexity:** `O(1)` for iterative binary search (no extra memory needed), `O(log n)` if using recursion (because of the call stack).

### Mathematical Foundation

Binary search leverages the properties of sorted data and logarithms. Each time you halve the search space, you’re essentially asking, "How many times can I divide n by 2 before I get to 1?"—which is `log₂(n)`.

---

## 3. Implementation Approach

Let’s build a mental model for tackling binary search problems on sorted arrays/lists:

### Step-by-Step Thinking

- **Ask Yourself:** Is the array/list sorted? If not, can I sort it or is there a sorted property I can use?
- **Define the Search Space:** Set your left and right pointers to cover the entire array.
- **Choose the Right Condition:**
  - Are you looking for an exact match? (e.g., "Binary Search")
  - Do you need to find the first/last occurrence? (e.g., "First Bad Version")
  - Are you searching for an insertion point? (e.g., "Search Insert Position")
  - Are you searching for a missing element or a boundary? (e.g., "Kth Missing Positive Number")
- **Update Pointers Carefully:** After checking the middle, decide which half to keep searching in. Be careful with off-by-one errors!
- **Handle Edge Cases:**
  - What if the target isn’t present?
  - What if the array is empty?
  - What if the target is smaller than all elements or larger than all elements?
  - For interactive problems (like "Guess Number Higher or Lower"), how does the feedback guide your next guess?

### Decision Tree

- Is the data sorted? If yes, proceed.
- Do you need an exact match? Use standard binary search.
- Do you need a boundary (first/last occurrence)? Adjust your mid and pointer updates accordingly.
- Do you need to find a missing or special value? Think about how to map the problem to a search for a boundary or count.

### Edge Cases Example

Suppose you’re searching for 5 in `[1, 3, 7, 9]`. Since 5 isn’t present, where would you insert it? Between 3 and 7. Your binary search should return the index where 5 would fit.

### Practical Tips

- Always check your loop condition: `while (left <= right)` is standard for searching for an exact match.
- For insertion points, sometimes you want `while (left < right)`.
- Use clear variable names: `left`, `right`, `mid`, `target`.
- Think about what happens when the array is empty or has only one element.

---

## 4. Practice Tips

### Signals to Use This Pattern:
- The data is sorted (or can be treated as sorted).
- You need to find, insert, or locate a boundary (first/last occurrence, missing value, etc.).
- The problem asks for O(log n) time.

### Aha! Moments:
- Realizing you don’t need to check every element—just keep halving!
- Understanding that the final value of your pointer (often left) can give you insertion points or boundaries.

### Debugging Tips:
- Watch out for off-by-one errors! Double-check your loop conditions and pointer updates.
- Print your left, right, and mid values during debugging to see how the search space changes.
- For edge cases, test empty arrays, single-element arrays, and targets outside the range.

### Memory Tricks:
- "Divide and Conquer" = "Cut the problem in half each time."
- Remember: Sorted + Search = Binary Search!

---

## 5. Practice Problems (LeetCode)

- [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
- [Sqrt(x)](https://leetcode.com/problems/sqrtx/)
- [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)
- [First Bad Version](https://leetcode.com/problems/first-bad-version/)
- [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)
- [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
- [Binary Search](https://leetcode.com/problems/binary-search/)
- [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)

---

> Keep practicing, and soon binary search will feel as natural as flipping to the right page in a book!

