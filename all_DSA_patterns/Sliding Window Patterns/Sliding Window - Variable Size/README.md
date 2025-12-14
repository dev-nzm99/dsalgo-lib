# Sliding Window Pattern: Variable Size (Condition-Based)

## 1. Pattern Overview
Imagine you’re looking through a long row of houses, searching for the largest group of houses where everyone is friendly with each other. You walk along the street, sometimes inviting more neighbors into your group, and sometimes asking someone to leave if they don’t fit the vibe. This is the essence of the **Variable Size Sliding Window** pattern.

Unlike a fixed-size window (where you always look at, say, exactly 3 houses at a time), here the window can grow or shrink depending on certain conditions. For example, you might want to keep all houses where the age difference between the oldest and youngest is at most 2 years, or where you only have two types of fruit in your basket at any time.

This pattern is incredibly useful when you need to find the longest or shortest subarray (or substring) that satisfies a certain property, like:
- The subarray contains at most `k` distinct elements.
- The sum of elements is less than a target.
- The difference between the max and min is within a limit.

### Everyday Analogy
Think of filling a shopping cart with groceries, but you can only carry up to two types of fruit at a time. As you shop, you add items, but if you pick up a third type, you have to remove something. The cart’s contents (your “window”) change size based on the rules.

---

## 2. Core Concepts
Let’s break down how this pattern works under the hood:

### How the Window Moves
- **Start with an empty window:** Both left and right pointers at the beginning.
- **Expand the window:** Move the right pointer to include more elements as long as the condition holds.
- **Shrink the window:** If the condition breaks (e.g., too many fruit types), move the left pointer forward to remove elements until the condition is restored.

### Key Tools
- **Hash Tables:** Track counts or types of elements in the window (e.g., how many of each fruit).
- **Queues/Deques:** For problems involving order or monotonicity (e.g., max/min in a window).
- **Counting:** Keep track of frequencies or sums efficiently.

### Visualizing the Process
Picture a highlighter moving over a line of text. You start highlighting from the left, moving right, and sometimes you need to erase from the left to keep your highlight within certain rules.

### Time & Space Complexity
- **Time:** Usually O(N), since each element is added and removed from the window at most once. Think of reading a book from start to end, never going back.
- **Space:** Depends on what you track. If you use a hash map for counts, space is O(K) where K is the number of unique elements in the window.

### Mathematical Foundation
At its core, this pattern is about maintaining invariants—rules that must always be true inside your window. You use two pointers to efficiently explore all possible subarrays that meet your criteria, without redundant work.

---

## 3. Implementation Approach
Let’s build a mental model for tackling these problems:

### Step-by-Step Thinking
1. **Identify the window property:** What condition must always be true inside the window? (e.g., at most 2 types of fruit, sum ≤ target, difference ≤ limit)
2. **Set up two pointers:** Usually left and right (or start and end), both starting at 0.
3. **Expand the window:** Move right forward, adding new elements and updating your tracking structures (like a hash map for counts).
4. **Check the condition:** After each addition, ask: “Does my window still satisfy the rule?”
5. **Shrink if needed:** If not, move left forward, removing elements and updating tracking structures until the rule is satisfied again.
6. **Track the answer:** For each valid window, update your result (e.g., max length, count, etc.).

### Decision Tree
- Does the window need to be as large as possible? Expand until the rule breaks, then shrink.
- Are you counting all valid windows? Sometimes you need to count every valid subarray, not just the largest.

### Edge Cases
- **Empty arrays:** What happens if there are no elements?
- **All elements are the same:** Does your code handle this efficiently?
- **Window shrinks to zero:** Make sure you don’t get stuck in an infinite loop.

### Example
In the **“Fruit Into Baskets”** problem, you want the longest subarray with at most 2 types of fruit. As you walk through the array, you add fruit types to your basket (hash map). If you pick up a third type, you remove fruit from the left until you’re back to two types.

---

## 4. PRACTICE PROBLEMS

Here are some classic LeetCode problems using the **Variable Size Sliding Window** pattern:

1. **Longest Substring Without Repeating Characters**
   - Find the length of the longest substring without repeating characters.
   - [LeetCode Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

2. **Substring with At Most K Distinct Characters**
   - Given a string, find the length of the longest substring that contains at most `k` distinct characters.
   - [LeetCode Link](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)

3. **Minimum Window Substring**
   - Given two strings `s` and `t`, find the minimum window in `s` which will contain all the characters in `t`.
   - [LeetCode Link](https://leetcode.com/problems/minimum-window-substring/)

4. **Permutation in String**
   - Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`.
   - [LeetCode Link](https://leetcode.com/problems/permutation-in-string/)

5. **Longest Subarray with At Most K Distinct Integers**
   - Find the length of the longest subarray with at most `k` distinct integers.
   - [LeetCode Link](https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-integers/)

---

The **Variable Size Sliding Window** pattern is an incredibly efficient and powerful technique for solving problems that involve finding subarrays or substrings that satisfy certain conditions. By maintaining a dynamic window that grows or shrinks based on specific criteria, this pattern allows you to optimize the process of exploring all possible subarrays without unnecessary recomputation. With practice, this pattern will become a vital tool in your problem-solving toolkit, especially for solving optimization problems related to arrays and strings.

