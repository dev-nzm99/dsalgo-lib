# Stack Patterns: Simulation / Backtracking Helper

## 1. Pattern Overview

Imagine you’re organizing a stack of plates in your kitchen. Every time you add a plate, it goes on top; when you need a plate, you take the top one off. Now, picture that you’re following a set of instructions—sometimes you need to undo your last action, sometimes you need to repeat a sequence, or maybe you need to keep track of where you are in a process. This is where the **Simulation / Backtracking Helper** stack pattern comes in.

This pattern acts as a “memory” of previous steps, useful for:

* Undo operations
* Nested or sequential actions
* Simulating processes with forward/backward movements

**Everyday Example:**
Navigating folders: push a folder when entering, pop when going back.

**Common Use Cases:**

* Processing items in order with possible undo
* Nested/recursive structures (like brackets)
* Simulating reversible processes

---

## 2. Core Concepts

### How Stacks Help Simulation and Backtracking

**Stack as History Keeper:**

* Stack stores steps; pop to undo.

**LIFO Principle:**

* Last-In-First-Out matches real-world undo operations.

**Simulation:**

* Track current state and update/remove previous events based on new input.

**Backtracking:**

* Nested structures (e.g., decoding strings with brackets) use stacks to track depth.

### Visualizing the Process

* Stack of cards represents steps/states.
* Push relevant info when processing input.
* Pop on “closing” events to revert or combine states.

### Complexity

* **Time:** O(n), each element processed once.
* **Space:** O(n) worst case (stack grows with depth).

### Mathematical Foundations

* Fundamental for recursion and parsing.
* Handles nested/reversible operations efficiently.

---

## 3. Implementation Approach

### Step-by-Step Thinking

**Identify Need:**

* Do you need to remember previous steps/states?
* Look for nested structures, undo operations, or reversible sequences.

**Decide What to Store:**

* Characters, numbers, partial results, or objects.
* Example: In string decoding, store current result and repeat count.

**Process Input Sequentially:**

* For each element, decide to push, pop/combine, or ignore.

**Handle Edge Cases:**

* Empty input, consecutive undo operations, nested/overlapping actions.

**Combine Results:**

* As you pop, merge with current state to build final answer.

### Decision Tree

* Need to remember previous states? → Stack
* Nested/recursive structures? → Stack for depth
* Simulating process with reversals? → Stack to undo/resolve conflicts

### Edge Case Examples

1. **Simplify Path**

   * Input: `/a/./b/../../c/`
   * `.` → stay, `..` → go back. Stack manages path.

2. **Decode String**

   * Input: `3[a2[c]]`
   * Nested brackets require tracking previous strings and counts.

3. **Asteroid Collision**

   * Input: `[5, 10, -5]`
   * Negative asteroid may destroy previous positive ones; stack resolves collisions.

### Practice Problems

1. **Simplify Path**

   * [LeetCode Link](https://leetcode.com/problems/simplify-path/)

2. **Decode String**

   * [LeetCode Link](https://leetcode.com/problems/decode-string/)

3. **Asteroid Collision**

   * [LeetCode Link](https://leetcode.com/problems/asteroid-collision/)

4. **Evaluate Reverse Polish Notation**

   * [LeetCode Link](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

5. **Basic Calculator**

   * [LeetCode Link](https://leetcode.com/problems/basic-calculator/)

---

This pattern is essential for simulating processes, managing nested structures, and implementing backtracking efficiently.
