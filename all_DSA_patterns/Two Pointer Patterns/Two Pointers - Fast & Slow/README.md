# Two Pointers Pattern: Fast & Slow (Cycle Detection)

## 1. Pattern Overview

Imagine you and a friend are walking around a circular track. You start together, but your friend walks twice as fast as you. If the track is a perfect circle and you both keep walking, eventually, your friend will lap you and catch up again. But if the track is a straight line, your friend will just keep getting farther ahead and never meet you again. This is the heart of the Fast & Slow Pointers (also called the "Tortoise and Hare") cycle detection pattern.

This pattern is incredibly useful when you need to detect cycles or repeated patterns in data structures like linked lists or arrays. It's like having two detectives following clues at different speeds—if there's a loop, the faster one will eventually catch up to the slower one inside the loop. If not, the faster one will reach the end and stop.

You'll often use this pattern when:

* You want to check if a linked list has a cycle (like a snake biting its own tail).
* You need to detect if a process will repeat forever or eventually stop (like checking if a number is "happy").
* You want to find a duplicate in a set of numbers without extra memory.

##

The Fast and Slow Pointer technique is a clever algorithmic approach used mainly in linked lists and arrays to detect patterns like cycles, midpoints, or duplicates — without using extra space.

It works by moving two pointers through a sequence at different speeds:
- Slow pointer (🐢) → moves one step at a time.
- Fast pointer (🐇) → moves two steps at a time.

Because the fast pointer moves quicker, it eventually “laps” or meets the slow pointer if there’s a loop (cycle).

<div align="center">
  <img src="https://github.com/dev-nzm99/DSA-Pathshala/blob/main/src/img/Screenshot%202025-11-01%20115407.png" alt="Banner" width="100%" />
</div>



---

## 2. Core Concepts

### How It Works

* **Two Pointers:** You use two variables (pointers), often called slow and fast.
* **Different Speeds:** The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
* **Meeting Point:** If there's a cycle, the fast pointer will eventually "lap" the slow pointer, and both will point to the same place.
* **No Cycle:** If there's no cycle, the fast pointer will reach the end (null or out of bounds) before the slow pointer.

### Visualizing the Process

Imagine a circular race track:

* If you and your friend keep walking at different speeds, you'll meet again if the track loops.
* If the track is straight, your friend will disappear into the distance.

### Time and Space Complexity

* **Time Complexity:** Usually O(N), where N is the number of elements. Both pointers traverse the structure, but since the fast pointer moves twice as fast, the number of steps is still proportional to N.
* **Space Complexity:** O(1), because you only use two pointers, no extra data structures.

Think of it like reading a book with two bookmarks—one moves one page at a time, the other two pages. If the book is circular (pages loop back), the bookmarks will overlap. If not, the faster one finishes first.

### Mathematical Foundation

The pattern works because, in a cycle, the distance between the two pointers reduces by one at each step (since fast moves two steps and slow one). Eventually, the gap closes, and they meet.

---

## 3. Implementation Approach

### Step-by-Step Thinking

1. **Identify the Structure:** Is the data structure "walkable" (like a linked list or array where you can move from one element to the next)?

2. **Ask Yourself:**

   * "Is there a possibility of a cycle or repeated state?"
   * "Can I move through the structure with two pointers at different speeds?"

3. **Set Up Pointers:**

   * Initialize both slow and fast pointers at the starting position.

4. **Move Pointers:**

   * In each iteration:

     * Move slow one step.
     * Move fast two steps.

5. **Check for Meeting:**

   * If slow and fast meet, a cycle exists.
   * If fast reaches the end, there's no cycle.

6. **Decision Tree:**

   * Is the structure a linked list or array?

     * Yes → Can you move from one element to the next? → Yes → Use Fast & Slow pointers.
     * No → This pattern might not fit.
   * Is the problem about cycles, repeats, or duplicates?

     * Yes → Try Fast & Slow pointers.

7. **Edge Cases:**

   * Empty Structure: If the list or array is empty, there's no cycle.
   * Single Element: Usually, no cycle unless it points to itself.
   * Self-Loop: If the first element points to itself, the pointers will meet immediately.

8. **Example:**

   * In a linked list: If head is null, return false (no cycle).
   * In an array: If moving by index, ensure you don't go out of bounds.

**Tip:** Always check that `fast` and `fast->next` (or their array equivalents) are valid before moving them, to avoid errors.

---

## 🧩 PRACTICE PROBLEMS

Here are some classic LeetCode problems using the Fast & Slow pointers pattern:

1. **Linked List Cycle**

   * Detect if a linked list has a cycle.
   * [LeetCode Link](https://leetcode.com/problems/linked-list-cycle/)

2. **Linked List Cycle II**

   * Find the node where the cycle begins.
   * [LeetCode Link](https://leetcode.com/problems/linked-list-cycle-ii/)

3. **Happy Number**

   * Determine if a number eventually reaches 1 by repeatedly replacing it with the sum of the squares of its digits.
   * [LeetCode Link](https://leetcode.com/problems/happy-number/)

4. **Find the Duplicate Number**

   * Find a duplicate number in an array without modifying it.
   * [LeetCode Link](https://leetcode.com/problems/find-the-duplicate-number/)

---

By practicing these problems, you'll gain mastery over the Fast & Slow Pointers pattern and be able to detect cycles efficiently in different data structures.
