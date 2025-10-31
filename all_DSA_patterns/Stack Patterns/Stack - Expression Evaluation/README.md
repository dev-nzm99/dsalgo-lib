# Stack Patterns: Expression Evaluation (RPN/Infix)

## 🧩 Pattern Overview

Imagine you’re solving math problems on paper. Sometimes you write expressions like `3 + 5 * 2`, and you have to remember to multiply before you add. Other times, you might see a calculator that lets you enter numbers and operators in a different order, like `3 5 2 * +` (Reverse Polish Notation, or RPN). Both ways, you’re juggling numbers and operations, keeping track of what to do next.

**Expression Evaluation** is about teaching computers to do this juggling for us. Whether infix (`3 + 5 * 2`) or RPN (`3 5 2 * +`), the computer needs a way to process numbers and operators in the right order. Stacks act like a pile of plates, letting us push things on top and pop them off when needed, which is perfect for nested calculations and operator precedence.

Applications include calculators, programming language interpreters, and spreadsheet formulas. Stacks help computers mimic step-by-step human problem solving, handling parentheses, operator order, and more.

---

## 🧠 Core Concepts

### 1. Stack as a Memory Aid

* For infix expressions (e.g., `2 + (3 * 4)`), the stack remembers operations and parentheses.
* For RPN (`2 3 4 * +`), the stack holds numbers until an operator is applied.

### 2. Operator Precedence

* Multiplication/division usually happen before addition/subtraction.
* Stack helps enforce these rules by delaying operations until appropriate.

### 3. Parentheses Handling

* Open parentheses → start a sub-calculation.
* Stack keeps track of where you left off.

### 4. Processing Order

* **Infix:** Scan left to right, push numbers and operators, pop when ready to calculate.
* **RPN:** Push numbers, pop two numbers on seeing an operator, compute, push result.

### 5. Complexity

* **Time Complexity:** O(N), N = expression length.
* **Space Complexity:** O(N), for stack holding numbers/operators.

### 6. Math Meets Code

* Stack is a practical way to implement “order of operations.”
* Recursion can be used for nested expressions, but stacks are explicit and easier to debug.

---

## 🛠️ Implementation Approach

### 1. Identify Expression Type

* **Infix:** Standard notation with operator precedence and parentheses.
* **RPN/Postfix:** Operators after operands, no parentheses needed.

### 2. Think Like This

* **Infix:** Push numbers, check if operators should be processed, handle parentheses.
* **RPN:** Push numbers, pop two numbers for operator, push result.

### 3. Ask Yourself

* Multi-digit numbers or spaces?
* How to handle parentheses?
* Operator precedence order?

### 4. Decision Tree

* **Infix with parentheses:** Two stacks (numbers + operators).
* **Simple infix (no parentheses):** One stack may suffice.
* **RPN:** One stack for numbers.

### 5. Edge Cases

* Negative numbers/unary minus.
* Division by zero.
* Empty or invalid input.

### 6. Example

Expression: `3 + (2 * 4)`

* Push 3
* See + → push operator
* See ( → push onto operator stack
* Push 2
* See * → push operator
* Push 4
* See ) → pop and compute 2*4, then add to 3

### 7. Practice Problems

1. **Evaluate Reverse Polish Notation**

   * [LeetCode Link](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

2. **Basic Calculator**

   * [LeetCode Link](https://leetcode.com/problems/basic-calculator/)

3. **Basic Calculator II**

   * [LeetCode Link](https://leetcode.com/problems/basic-calculator-ii/)

4. **Basic Calculator III**

   * [LeetCode Link](https://leetcode.com/problems/basic-calculator-iii/)

5. **Parse Lisp Expression**

   * [LeetCode Link](https://leetcode.com/problems/parse-lisp-expression/)

---

This pattern is essential for building reliable expression evaluators and understanding stack-based computation.
