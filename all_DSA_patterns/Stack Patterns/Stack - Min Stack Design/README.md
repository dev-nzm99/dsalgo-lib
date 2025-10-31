# Stack Patterns: Min Stack Design

🟦 **PATTERN OVERVIEW**  
Imagine you have a stack of books on your desk. You can only add or remove the book on the very top—this is the classic "last in, first out" (LIFO) rule. Now, suppose you want to know, at any moment, which book in your stack is the thinnest (i.e., has the minimum thickness). But here's the catch: you want to find the thinnest book instantly, without flipping through the whole stack every time.

This is exactly what the **Min Stack Design** pattern is about. It's a special kind of stack that, in addition to the usual `push` and `pop` operations, can also tell you the **minimum element currently in the stack in constant time**—no matter how many elements are inside.

**Use Cases:**  
- Stock price monitoring: Track the lowest price in a recent window of trades.  
- Undo operations: Maintain the "minimum" state in a series of changes.  
- Game scores: Quickly find the lowest score among recent plays.  

---

🟦 **CORE CONCEPTS**  

**Naive approach:** Scan the entire stack each time → O(n) time.  

**Min Stack approach:** Maintain the minimum at all times → O(1) time.  

**The Trick: Use Two Stacks**  
- **Main Stack:** Stores all values as usual.  
- **Min Stack:** Keeps track of the minimum value at each level.  

**How it works:**  
- On `push`, add the value to the main stack. Also push the **current minimum** (new value or previous min) onto the min stack.  
- On `pop`, remove elements from both stacks.  
- On `getMin`, return the top of the min stack.  

**Example:**  

| Operation | Main Stack     | Min Stack       |
|-----------|----------------|----------------|
| push 3    | 3              | 3              |
| push 5    | 3, 5           | 3, 3           |
| push 2    | 3, 5, 2        | 3, 3, 2        |
| push 1    | 3, 5, 2, 1     | 3, 3, 2, 1     |
| push 4    | 3,5,2,1,4      | 3,3,2,1,1      |

The top of the **min stack** always gives the current minimum.

**Complexity:**  
- **Time:** O(1) for all operations (`push`, `pop`, `top`, `getMin`)  
- **Space:** O(n) for storing the min stack  

---

🟦 **IMPLEMENTATION APPROACH**  

1. **Think Like This:**  
   - How can I always know the minimum, even as I add/remove elements?  
   - Can I keep a history of minimums as I build the stack?  

2. **Push Logic:**  
   - If new value < current minimum → push new value to min stack.  
   - Else → push current minimum again.  

3. **Pop Logic:**  
   - Pop from both main stack and min stack.  

4. **Get Minimum:**  
   - Return the top of min stack.  

5. **Edge Cases:**  
   - **Empty stack:** Check before popping or retrieving top/min.  
   - **Duplicate minimums:** Record each occurrence in the min stack to avoid losing track.  

6. **Visual Analogy:**  
   Imagine a stack of plates where each plate has a number (its thickness). Each time you add a plate, you also place a sticky note with the thinnest plate so far. Removing a plate also removes its sticky note. The top sticky note always tells you the thinnest plate.  

**Alternative Approach:**  
Only push to the min stack when a new minimum is encountered. Pop only when the minimum is removed. This is space-efficient but slightly more complex.

---

🟦 **PRACTICE PROBLEMS**  

1. **Min Stack** – Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.  
   [LeetCode Link](https://leetcode.com/problems/min-stack/)  

2. **Sliding Window Minimum** – Find the minimum in every subarray of size k.  
   [LeetCode Link](https://leetcode.com/problems/sliding-window-maximum/)  

3. **Max Stack** – Variant: Maintain the maximum element in a stack efficiently.  
   [LeetCode Link](https://leetcode.com/problems/max-stack/)  

---

This pattern is a must-know for **efficient stack design**, enabling constant-time access to the minimum element while supporting regular stack operations.
