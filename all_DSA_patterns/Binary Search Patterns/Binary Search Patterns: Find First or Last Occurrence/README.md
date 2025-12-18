# Binary Search Patterns: Find First/Last Occurrence

## 1. Pattern Overview
Imagine you’re searching for a particular word in a thick, alphabetized dictionary. If you know the word appears more than once, you might want to find the very first or last page where it’s listed. Instead of flipping through every page, you’d probably jump to the middle, see if you’re too early or too late, and then narrow your search—this is the essence of binary search.

The **Find First/Last Occurrence** subpattern takes this idea a step further. It’s not just about finding if something exists, but where it starts and ends within a sorted list. Think of a playlist sorted by song title: if you want to find all versions of “Imagine,” you’d want to know the first and last spot it appears.

This pattern is incredibly useful in scenarios where data is sorted and you need precise boundaries—like finding the range of a target value in a database, or identifying the window of closest elements to a number. It’s a favorite in technical interviews at companies like Amazon, Google, and Facebook because it tests both your problem-solving and your ability to optimize with binary search.

**Everyday analogy:** Imagine looking for a specific chapter in a book that appears multiple times (maybe as a recurring theme). Instead of reading every page, you’d want a way to quickly jump to the first and last occurrence—saving time and effort.

---

## 2. Core Concepts
Let’s break down the main ideas behind this subpattern:

### a. Binary Search Basics
- Binary search is like playing a guessing game: you always check the middle of your current range, then cut your search space in half based on what you find.
- It only works on sorted data—like a phonebook or a sorted array.

### b. First vs. Last Occurrence
- Standard binary search tells you if an element exists, but not where it starts or ends.
- To find the **first occurrence**, you keep searching even after you find your target—always checking if there’s another occurrence to the left.
- To find the **last occurrence**, you do the same but look to the right.

### c. Time and Space Complexity
- **Time:** Binary search is fast—think of reading a book by jumping to the middle, then the quarter, then the eighth, etc. It takes at most O(log n) steps, where n is the size of your list.
- **Space:** Most binary search implementations use constant space (O(1)), since you only track a few pointers (like left, right, and mid).

### d. Visualizing the Process
Picture a row of lockers, each labeled with a number. You want to find the first and last locker with a specific number. You start in the middle, then move left or right based on what you find, narrowing your search each time. The process is like zooming in with a camera lens: each step brings you closer to the exact boundary you’re looking for.

### e. Mathematical Foundation
Binary search relies on the fact that sorted data lets you eliminate half the possibilities with each step. This exponential reduction is what makes it so efficient.

---

## 3. Implementation Approach
Let’s build a mental model for tackling these problems:

### Step 1: Recognize the Pattern
Ask yourself: “Is the data sorted? Am I looking for a boundary (first/last) or a window (closest elements)?”
- If yes, binary search is likely the way to go.

### Step 2: Set Up Your Pointers
Typically, you’ll use two pointers: left (start of the array) and right (end of the array).
- You’ll repeatedly calculate the mid index: `mid = left + (right - left) / 2`.

### Step 3: Modify Binary Search for Boundaries
#### First Occurrence:
- If you find the target, don’t stop! Move right to `mid - 1` to see if there’s another occurrence to the left.
- Keep track of the latest index where you found the target.

#### Last Occurrence:
- If you find the target, move left to `mid + 1` to check for more occurrences to the right.
- Again, record the index when you find the target.

### Step 4: Edge Cases to Watch For
- **Target not present:** Return `[-1, -1]` or an empty result.
- **All elements are the target:** Both first and last occurrence will be at the ends.
- **Single-element arrays:** Make sure your code doesn’t go out of bounds.

### Step 5: For Closest Elements (e.g., "Find K Closest Elements")
- Use binary search to find the best starting point for a window of size k.
- Compare distances to decide which window is closest to the target.

##

## Decision Tree:
- **Do I need a specific index or a window?**
  - If **index:** Use boundary binary search.
  - If **window:** Use binary search to find the best starting point.

##

### Example Edge Case:
Array: `[5, 7, 7, 8, 8, 10]`, target: `8`
- **First occurrence:** index 3
- **Last occurrence:** index 4

---
## 6. Practice Problems:
### Binary Search on Answer/Condition Function Practice

| #  | Problem                                                        | Difficulty | LeetCode Link                                                   |
|----|----------------------------------------------------------------|-----------|-----------------------------------------------------------------|
| 1  | Find First and Last Position of Element in Sorted Array        | Medium    | [Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) |
| 2  | Find K Closest Elements                                         | Medium    | [Link](https://leetcode.com/problems/find-k-closest-elements/)  |


---

## 5. Practice Tips

### Signals to Look For:
- The data is sorted.
- The problem asks for a range, boundary, or window.
- You need to find "first," "last," or "closest" occurrences.

##

### Aha! Moments:
- Realizing you can keep searching after finding the target to find true boundaries.
- Understanding that binary search isn’t just for existence—it’s for precision.

##

### Debugging Tips:
- Watch for off-by-one errors with pointers.
- Check what happens when the target is at the start or end.
- Test with empty arrays and arrays with all identical elements.

##

### Memory Tricks:
- “Left for first, right for last”—when you find the target, move left to find the first, right to find the last.

##

With practice, you’ll spot these patterns quickly and apply binary search with confidence!


