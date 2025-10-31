# Two Pointers Pattern: Converging (Sorted Array Target Sum)

## 🧭 PATTERN OVERVIEW

Imagine you and a friend are standing at opposite ends of a long bookshelf, looking for two books whose page counts add up to a specific number. Instead of both of you searching the entire shelf, you each start at one end and move toward each other, comparing the books you find. If the combined page counts are too low, your friend moves forward; if they're too high, you step back. This is the essence of the Converging Two Pointers pattern.

This subpattern is especially powerful when working with sorted arrays or sequences. It lets you efficiently find pairs (or even triplets) of values that meet a certain condition—like adding up to a target sum—without checking every possible combination. Think of it as a smart, coordinated search rather than a brute-force hunt.

You'll see this pattern shine in scenarios like:

* Finding two numbers in a sorted list that sum to a target (like splitting a bill between two people).
* Identifying unique triplets in an array that sum to zero (like balancing a budget with three expenses).
* Merging or comparing two sorted lists (like finding common friends in two sorted contact lists).
* Maximizing container water or minimizing boat usage.

By moving pointers inward from both ends, you can quickly "zero in" on the answer, making this approach both intuitive and efficient for many real-world and coding interview problems.

---

## 🔍 CORE CONCEPTS

At its heart, the Converging Two Pointers technique is about using two markers (pointers) to scan a sorted array from both ends toward the center. Here’s how it works:

### Why Sorted Arrays?

Sorting brings order. When you know the smallest and largest values are at the ends, you can make smart decisions about which direction to move.
For example, if you want two numbers that add up to 10, and your current pair adds up to 8, you know you need a bigger number—so move the left pointer right.

### How the Pointers Move:

* **Left Pointer:** Starts at the beginning (smallest value).
* **Right Pointer:** Starts at the end (largest value).
* At each step, you check the sum (or another condition) of the values at both pointers.

  * If the sum is too small, move the left pointer right (to a larger value).
  * If the sum is too big, move the right pointer left (to a smaller value).
  * If the sum matches the target, you've found a solution!

### Efficiency:

Instead of checking every pair (which would be O(n²) time), you only scan the array once—O(n) time.

### Space Complexity:

Usually O(1) extra space, since you’re just moving pointers around in the existing array.

### Beyond Pairs:

For problems like "3Sum," you can fix one pointer and use two more to find pairs, extending the idea to triplets.

---

## 🛠️ IMPLEMENTATION APPROACH

1. **Recognize the Pattern**

   * Check if the array is sorted or can be sorted.
   * Look for pairs, triplets, or quadruplets matching a condition.
2. **Set Up Your Pointers**

   * Left at start, right at end.
   * Fix one element for triplet or quadruplet problems.
3. **Iterate and Compare**

   ```
   while left < right:
       sum = array[left] + array[right]
       if sum == target: record solution
       elif sum < target: left += 1
       else: right -= 1
   ```
4. **Handle Duplicates (if needed)**
5. **Edge Cases**
6. **Decision Tree**
7. **Think Like This**
8. **Example Edge Case**

   * `nums = [-4, -1, 0, 3, 10]`, `target = 6`

---

## 🧩 PRACTICE PROBLEMS

Here are some classic LeetCode problems using the Converging Two Pointers pattern:

1. **Two Sum II - Input Array Is Sorted**

   * Find two numbers that add up to a target.
   * [LeetCode Link](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

2. **3Sum**

   * Find all unique triplets that sum to zero.
   * [LeetCode Link](https://leetcode.com/problems/3sum/)

3. **4Sum**

   * Find all unique quadruplets that sum to a target.
   * [LeetCode Link](https://leetcode.com/problems/4sum/)

4. **Container With Most Water**

   * Maximize area formed between two lines.
   * [LeetCode Link](https://leetcode.com/problems/container-with-most-water/)

5. **Boats to Save People**

   * Minimize the number of boats to carry people given weight limits.
   * [LeetCode Link](https://leetcode.com/problems/boats-to-save-people/)

---

By practicing these problems, you'll gain mastery over the Converging Two Pointers pattern in multiple contexts.
