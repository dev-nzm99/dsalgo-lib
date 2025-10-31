# Stack Patterns: Valid Parentheses Matching

## 🧩 Pattern Overview

Imagine you’re stacking plates in your kitchen: every time you put a plate on the stack, you expect to remove it in the reverse order you placed it. This is the essence of the stack data structure—a “last in, first out” (LIFO) system. Now, think of parentheses in a math equation or code: every opening bracket `(`, `{`, or `[` must be matched and closed in the correct order. If you open a bracket, you need to close it before closing any previous ones—just like you can’t remove a plate from the middle of your stack!

Valid Parentheses Matching ensures every opening bracket has a corresponding closing bracket and they’re properly nested. This pattern is crucial in:

* **Code editors:** Checking if your code’s brackets are balanced.
* **Math expressions:** Ensuring formulas are correctly structured.
* **HTML/XML parsing:** Making sure tags are properly opened and closed.

Whenever you need to verify or manipulate nested structures—like undo/redo operations, parsing expressions, or checking if a string is a palindrome—stack patterns, especially parentheses matching, come into play.

---

## 🔑 Core Concepts

### 1. Stack as a Memory Aid

Think of a stack as a pile of sticky notes. Every time you see an opening bracket, you write it down and stick it on top. When you see a closing bracket, you check the top sticky note:

* If it matches, remove it.
* If not, the string is invalid.

### 2. Matching Rules

* Every opening bracket must be closed by the same type (e.g., `(` with `)`).
* Brackets must close in the correct order—no skipping or mismatching.

### 3. Algorithmic Steps

1. Scan the string from left to right.
2. Push opening brackets onto the stack.
3. When a closing bracket appears, pop from the stack and check for a match.
4. After processing, the stack should be empty for a valid string.

### 4. Complexity

* **Time Complexity:** O(n), where n is the string length.
* **Space Complexity:** O(n) in the worst case (all opening brackets).

### 5. Extensions

Some related problems include:

* Counting the minimum number of changes to make a string valid.
* Finding the longest valid substring.
* Balancing brackets with the fewest swaps.

These might use stacks, two pointers, or dynamic programming.

---

## 🛠️ Implementation Approach

### 1. Identify the Problem Type

Ask yourself:

* Check if the string is valid?
* Make the string valid (add/remove/swaps)?
* Find the longest valid part?

### 2. Choose Your Tools

* **Stack:** Track open brackets and match closes.
* **Counters:** Count unmatched opens/closes.
* **Two Pointers:** For substrings or balancing from both ends.

### 3. Step-by-Step Process

**Basic Validation:**

1. Initialize an empty stack.
2. Iterate through each character:

   * If opening bracket → push onto stack.
   * If closing bracket → check stack:

     * Empty stack → invalid.
     * Top matches → pop.
     * Else → invalid.
3. Stack should be empty at the end for a valid string.

**Making Valid:**

* Track indices of unmatched brackets.
* Remove/add brackets to balance.

**Longest Valid Substring:**

* Use stack for indices or counters to track balance.
* Track maximum length found.

### 4. Edge Cases

* Empty string → usually valid.
* Strings with only one type of bracket.
* Strings with letters or other characters mixed in.

### 5. Visual Example

For `s = "([{}])"`:

* Push `(` → stack: `(`
* Push `[` → stack: `([`
* Push `{` → stack: `([{`
* See `}` → matches `{`, pop → stack: `([`
* See `]` → matches `[`, pop → stack: `(`
* See `)` → matches `(`, pop → stack empty → valid!

---

## 6. Practice Problems

1. **Valid Parentheses**
   - [LeetCode Link](https://leetcode.com/problems/valid-parentheses/)

2. **Longest Valid Parentheses**
   - [LeetCode Link](https://leetcode.com/problems/longest-valid-parentheses/)

3. **Minimum Add to Make Parentheses Valid**
   - [LeetCode Link](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

4. **Score of Parentheses**
   - [LeetCode Link](https://leetcode.com/problems/score-of-parentheses/)

5. **Remove Outermost Parentheses**
   - [LeetCode Link](https://leetcode.com/problems/remove-outermost-parentheses/)
