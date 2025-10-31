# Stack Patterns: Monotonic Stack

## 1. Pattern Overview

Imagine you’re stacking plates in a cafeteria. Each new plate you add is either bigger, smaller, or the same size as the previous one. If you want to always keep the biggest plate on top, you’ll need to remove smaller plates before adding a bigger one. This is the core idea behind the **Monotonic Stack** pattern—a special kind of stack that always keeps its elements in a certain order (increasing or decreasing).

A **Monotonic Stack** is a stack data structure where the values are always either increasing or decreasing from bottom to top. Think of it as a stack of books sorted by thickness: you might want the thinnest book always on top (increasing) or the thickest (decreasing).

This pattern is useful when you need to quickly find the “next greater” or “next smaller” element for each item in a list—like predicting the next warmer day, the next higher stock price, or applying discounts based on future prices. It allows efficient one-pass processing while keeping track of potential candidates for your answer.

Monotonic stacks are commonly asked in interviews at Google, Amazon, Facebook, and are essential for array and stack manipulation problems.

---

## 2. Core Concepts

### What is a Monotonic Stack?

* A stack that maintains a monotonic order—either strictly increasing or decreasing.
* In a monotonically increasing stack, each new element pushed is greater than or equal to the one below it.

### Why use it?

* Solves “next greater” or “next smaller” problems in **O(n)** time instead of **O(n²)**.
* Think of reading a book page by page vs. flipping randomly. Monotonic stacks let you process the list just once.

### How does it work?

1. Iterate through an array.
2. Use a stack to keep track of indices or values that might be an answer for future elements.
3. When a value breaks the monotonic order, pop elements from the stack and update answers.

### Visualization

* Picture dominoes with different heights. For each domino, you want the next taller domino on the right.
* Keep a stack of dominoes that haven’t found a taller neighbor yet.
* When a taller one appears, knock down shorter dominoes in the stack (update their answers).

### Complexity

* **Time Complexity:** O(n) — each element is pushed and popped at most once.
* **Space Complexity:** O(n) — stack and output array.

### Mathematical Foundation

* Stack acts as a memory of unresolved elements.
* Maintaining monotonicity ensures each comparison is meaningful and elements are never revisited unnecessarily.

---

## 3. Implementation Approach

### Step-by-Step Thinking

1. Ask yourself: Are we looking for the “next greater” or “next smaller” element?
2. Decide the stack type:

   * **Next Greater?** Use decreasing stack (top is biggest so far).
   * **Next Smaller?** Use increasing stack.
3. Decide what to store:

   * Usually **indices** to update answer array in-place.
4. Iterate through elements:

   * While stack is not empty and current element breaks monotonic order, pop from stack and update answers.
   * Push current index onto stack.

### Edge Cases

* No “next greater” or “next smaller” element → set default (-1 or 0).
* Circular arrays → may iterate twice.

### Decision Tree

* Is the problem about finding next/previous greater/smaller element?

  * Yes → Monotonic stack.
  * No → Consider other patterns.
* Direction:

  * Next → left-to-right.
  * Previous → right-to-left.

### Example Edge Case

* Last day in temperature array is the hottest → no warmer day after it → answer = 0.

### Practical Example

* Supermarket scenario: For each item, find if a cheaper item comes next.
* Use a **monotonic increasing stack** to track items without a cheaper price yet.

---

## 4. Practice Problems

1. **Next Greater Element I**

   * [LeetCode Link](https://leetcode.com/problems/next-greater-element-i/)

2. **Next Greater Element II (Circular Array)**

   * [LeetCode Link](https://leetcode.com/problems/next-greater-element-ii/)

3. **Daily Temperatures**

   * [LeetCode Link](https://leetcode.com/problems/daily-temperatures/)

4. **Largest Rectangle in Histogram**

   * [LeetCode Link](https://leetcode.com/problems/largest-rectangle-in-histogram/)

5. **Trapping Rain Water**

   * [LeetCode Link](https://leetcode.com/problems/trapping-rain-water/)

---

By practicing these problems, you'll gain mastery over the Monotonic Stack pattern in multiple contexts.
