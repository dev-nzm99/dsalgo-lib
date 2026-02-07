# Subpattern: In-place Reversal

## 1.Pattern Overview

The In-place Reversal pattern is a technique used to reverse the order of nodes in a linked list by modifying their pointers. Instead of creating a new list, you change the direction of the existing links so they point to the previous node rather than the next one.

You should use this pattern when you need to change the order of elements while keeping memory usage to a minimum. It is the most efficient way to reverse a list because it avoids the overhead of creating new node objects or using a stack.

- Reversing an entire singly linked list from start to finish.
- Reversing a specific portion of a list between two given positions.
- Reversing every k-sized group of nodes within a list.
- Reversing the second half of a list to determine if the sequence is a palindrome.

This pattern operates in **O(N)** time complexity because it only requires a single pass through the list. It achieves **O(1)** space complexity because it only uses a few pointer variables to track the current, previous, and next nodes.

---

## 2.CORE CONCEPTS

Let’s break down the key ideas behind in-place reversal of linked lists:

### Linked List Basics

A linked list is a sequence of nodes, where each node points to the next. Unlike arrays, you can’t jump to the middle; you have to walk node by node.

### Pointer Manipulation

The “magic” of in-place reversal comes from changing the next pointers of nodes. Imagine each node as a person in a conga line: you tell each person to grab the hand of the person behind them instead of the person in front!

### Two Pointers

You often use two (or three) pointers:

- `prev` (previous node)
- `curr` (current node)
- Sometimes `next` (to remember where you’re going next)

This helps you reverse direction without losing track of the rest of the list.

### Stack and Recursion

While in-place reversal is usually done iteratively, you can also use a stack or recursion to reverse a list, especially for problems like checking palindromes.

### Time and Space Complexity

- **Time:** You visit each node once—like reading a book page by page—so it’s O(n), where n is the number of nodes.
- **Space:** In-place means O(1) extra space (no new list, no big stack), except for recursion-based approaches which use O(n) stack space.

### Mathematical Foundation

Reversal is about inverting relationships: if node A pointed to B, after reversal, B points to A. The process is systematic and can be reasoned about step by step.

### Practical Use

In-place reversal is a building block for many advanced linked list problems, like reversing sublists, checking palindromes, or even merging lists in reverse order.

---

## 3.IMPLEMENTATION APPROACH

Let’s build a mental model for tackling in-place reversal problems:

### Think Like This

- “If I want to reverse a list, I need to change the direction of the arrows (pointers) between nodes.”
- “I need to keep track of where I am, where I came from, and where I’m going next.”

### Step-by-Step Plan

#### Initialize Pointers

- Set `prev` to `nullptr` (no node before the head).
- Set `curr` to the head of the list.

#### Iterate Through the List

For each node:

1. Save `curr->next` in a temporary pointer (`nextNode`) so you don’t lose the rest of the list.
2. Point `curr->next` to `prev` (reverse the link).
3. Move `prev` to `curr` (step forward).
4. Move `curr` to `nextNode` (continue).

#### Finish

When `curr` becomes `nullptr`, `prev` is the new head of the reversed list.

### Decision Trees

#### Full Reversal

Use the above approach for the whole list.

#### Partial Reversal (e.g., Reverse Linked List II)

- Traverse to the start of the sublist.
- Reverse only the specified section.
- Carefully reconnect the reversed part to the rest.

#### Palindrome Check

- Find the middle of the list (using slow/fast pointers).
- Reverse the second half in-place.
- Compare both halves node by node.

### Edge Cases

- Empty List: Head is `nullptr` — nothing to reverse.
- Single Node: No effect; reversal is the same as the original.
- Two Nodes: Simple swap of pointers.
- Reversing at the Head or Tail: Be careful to update the head pointer after reversal.

### Ask Yourself

- “Am I allowed to change the original list?”
- “Do I need to reverse the entire list or just a part?”
- “How do I reconnect the reversed section to the rest?”

---

## 4. Prectice Problems:

### In-place Reversal Pattern Practice – Linked Lists

| # | Problem                                   | Difficulty | LeetCode Link |
|---|-------------------------------------------|-----------|---------------|
| 1 | Reverse Linked List                       | Easy      | https://leetcode.com/problems/reverse-linked-list/ |
| 2 | Reverse Linked List II                    | Medium    | https://leetcode.com/problems/reverse-linked-list-ii/ |
| 3 | Reverse Nodes in k-Group                  | Hard      | https://leetcode.com/problems/reverse-nodes-in-k-group/ |
| 4 | Palindrome Linked List                    | Easy      | https://leetcode.com/problems/palindrome-linked-list/ |
| 5 | Remove Duplicates from Sorted List        | Easy      | https://leetcode.com/problems/remove-duplicates-from-sorted-list/ |
| 6 | Remove Duplicates from Sorted List II     | Medium    | https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ |
****

