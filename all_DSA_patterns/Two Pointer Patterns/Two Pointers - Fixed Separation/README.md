# Two Pointers Pattern: Fixed Separation (Nth Node from End)

## 1. Pattern Overview

Imagine you’re reading a book with a friend. You both start at the first page, but your friend reads a little ahead of you—say, five pages ahead. As you both turn pages together, your friend always stays five pages in front. When the friend finishes the book, you’ll be exactly five pages from the end. This is the essence of the Fixed Separation two pointers pattern.

In coding, especially with linked lists, we often need to find or remove a node that’s a specific distance from the end—like the “Nth node from the end.” Since linked lists don’t allow jumping to the end or counting backwards easily, the fixed separation trick provides an efficient one-pass solution.

You'll see this pattern in problems like:

* Finding the middle of a list (splitting a group in half)
* Removing the Nth node from the end (crossing off the 3rd last item)
* Deleting the middle node (removing the person in the center of a line)

This approach is highly favored in coding interviews because it tests logic and your understanding of relationships and distances in a data structure.

---

## 2. Core Concepts

### The Two Pointers

* **Pointer 1 (slow):** Starts at the head of the list.
* **Pointer 2 (fast):** Starts at the head, moves N steps ahead (or moves twice as fast for middle detection).

Visualize it: Two runners on a track. The fast runner starts N meters ahead. When the fast runner finishes, the slow runner is exactly N meters from the finish line.

### Why Not Just Count?

* Linked lists don’t have indexes like arrays.
* Counting the length first requires two passes.
* Two pointers traverse the list once — O(n) time, O(1) space.

### Step-by-Step Thinking

1. Advance fast pointer by N steps.
2. Move both pointers together (one node at a time).
3. When fast pointer reaches the end, slow pointer is at the target node.

### Complexity

* **Time Complexity:** O(n) — traverse the list once.
* **Space Complexity:** O(1) — only two pointers used.

### Mathematical Foundation

* If the list has L nodes and you want the Nth from the end:

  * Fast pointer moves N steps ahead.
  * Both move together until fast pointer hits the end (L - N steps).
  * Slow pointer is at (L - N)th node from the start, which is Nth from the end.

---

## 3. Implementation Approach

### Think Like This

* Do I need to find or remove a node a certain distance from the end? → Fixed separation.
* Can I process the list in one pass? → Two pointers.

### Step-by-Step Strategy

1. Set up two pointers: Both at the head.
2. Advance the fast pointer N steps ahead (for Nth from end problems).
3. If finding the middle, move fast pointer two steps for every slow step.
4. Move both pointers together until the fast pointer reaches the end.

### Handle Edge Cases

* N equals list length → may need to remove head.
* Single node → removing only node returns nullptr.
* Even number of nodes → decide first or second middle.
* Empty list → always check for null input.

### Example

* List: 1 → 2 → 3 → 4 → 5, remove 2nd node from the end:

  1. Move fast pointer 2 steps: now at 3.
  2. Move both pointers until fast is at the end.
  3. Slow pointer is at 3, so remove 4.

---

## 🧩 PRACTICE PROBLEMS

1. **Remove Nth Node From End of List**

   * [LeetCode Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

2. **Middle of the Linked List**

   * [LeetCode Link](https://leetcode.com/problems/middle-of-the-linked-list/)

3. **Delete Node in a Linked List**

   * [LeetCode Link](https://leetcode.com/problems/delete-node-in-a-linked-list/)

4. **Reorder List**

   * [LeetCode Link](https://leetcode.com/problems/reorder-list/)

---

By practicing these problems, you'll master the Fixed Separation two pointers pattern and efficiently solve linked list distance-based challenges.
