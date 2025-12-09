# Binary Search Patterns: On Answer / Condition Function

<p align="left">
  <a href="https://www.geeksforgeeks.org/dsa/binary-search-on-answer-tutorial-with-problems/" target="_blank">
    <img src="https://img.shields.io/badge/GFG%20Article%20-%233F8D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white&labelColor=%233F8D46&color=4CAF50" alt="How this approach works?" />
  </a>
</p>

##

## 1. Pattern Overview

Imagine you’re trying to guess a secret number between 1 and 100. Each time you guess, you’re told whether your guess is too high or too low. Instead of checking every number one by one, you can quickly narrow down the possibilities by always guessing the middle number. This is the essence of binary search.

But what if you’re not searching for a specific number, but for the best or minimum/maximum possible answer that satisfies a certain condition? This is where the Binary Search on Answer (also called "Binary Search on Condition Function") pattern shines.

Think of it like adjusting the volume on your headphones: you want it just right—not too loud, not too soft. You can’t check every possible volume, but you can keep adjusting up or down based on whether it feels too loud or too quiet. In coding, this means you’re searching for the smallest (or largest) value that meets a requirement, using a function that tells you whether your current guess is "good enough."

This pattern is especially useful when:

- The answer lies within a range (like minimum speed, maximum capacity, smallest possible limit, etc.)
- You can check if a candidate answer is valid using a helper function (the "condition function")
- The condition is monotonic: as you increase (or decrease) your guess, the outcome only flips from false to true (or vice versa) once

You’ll find this pattern in real-world scenarios like dividing work among people, shipping packages within deadlines, or allocating resources fairly.

---

## 2. Core Concepts

Let’s break down the key ideas behind Binary Search on Answer/Condition Function:

### The Monotonic Condition

The heart of this pattern is a monotonic condition function—a test that, as you increase or decrease your guess, flips from false to true (or vice versa) at some point and stays that way.

**Example:** "Can I ship all packages in D days if the ship’s capacity is X?" As X increases, it becomes easier to ship within D days.

### The Search Space

Instead of searching through an array, you’re searching through a range of possible answers (often integers).  
You define the lowest possible value (e.g., the heaviest single package) and the highest possible value (e.g., the sum of all package weights).

### The Condition Function

For each guess, you run a helper function to check if it’s a valid answer.  
This function is usually greedy or uses prefix sums, and sometimes dynamic programming if the condition is complex.

### Time and Space Complexity

- **Time:** Each binary search step halves the search space, so you get O(log(range)) iterations.  
  Each iteration runs the condition function, which is usually O(N) for arrays of size N.  
  **Total time:** O(N * log(range))

  Imagine reading a book: instead of reading every page, you check a few key pages to see if you’ve found the chapter you want, and each check is a quick scan.

- **Space:** Usually O(1) or O(N) depending on the helper function.

### Mathematical Foundation

The pattern relies on the [Intermediate Value Theorem](https://www.geeksforgeeks.org/maths/intermediate-value-theorem/): if the function flips from false to true, there’s a boundary point where the answer lies.  
The key is that the function is monotonic—it never flips back.

---

## 3. Implementation Approach

Let’s walk through the mental steps to solve these problems:

### Step 1: Identify the Search Space

Ask yourself: What is the minimum and maximum possible value for the answer?  
For shipping packages: min is the heaviest package, max is the sum of all weights.  
For dividing candies: min is 1, max is the largest pile.

### Step 2: Define the Condition Function

Think like this: If I fix my guess at mid, can I achieve the goal?  
For each guess, write a function like `bool canDo(mid)` that returns true if the guess is feasible.  
This function often uses greedy logic: simulate the process and check if it works.

### Step 3: Binary Search Loop

Use a standard binary search:  
While low < high:  
- Set mid = (low + high) / 2  
- If canDo(mid) is true, try a smaller/better answer (high = mid)  
- Else, try a bigger answer (low = mid + 1)

At the end, low (or high) is your answer.

### Step 4: Handle Edge Cases

Examples:  
- What if all items are the same size?  
- What if the number of days or operations is 1 (must do everything at once)?  
- What if the answer is at the boundary (min or max)?

### Step 5: Validate

After finding the answer, double-check with the condition function to ensure correctness.

---

## 4. Decision Tree

### When to use this pattern:

- The problem asks for a minimum/maximum possible value.
- You can check feasibility for a given value.
- The feasibility check is monotonic.

---

## 5. Visual Example

Picture a slider from 1 to 100. Each time you move the slider, you ask, “Is this good enough?” and adjust left or right based on the answer.

---

## 6. Practice Problems:
### Binary Search on Answer/Condition Function Practice

| #  | Problem                                                        | Difficulty | LeetCode Link                                                   |
|----|----------------------------------------------------------------|-----------|-----------------------------------------------------------------|
| 1  | Split Array Largest Sum                                        | Hard      | https://leetcode.com/problems/split-array-largest-sum/           |
| 2  | Minimize Max Distance to Gas Station                           | Hard      | https://leetcode.com/problems/minimize-max-distance-to-gas-station/ |
| 3  | Koko Eating Bananas                                            | Medium    | https://leetcode.com/problems/koko-eating-bananas/              |
| 4  | Capacity To Ship Packages Within D Days                        | Medium    | https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ |
| 5  | Minimum Number of Days to Make m Bouquets                      | Medium    | https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/ |
| 6  | Minimum Limit of Balls in a Bag                                | Medium    | https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/  |
| 7  | Minimized Maximum of Products Distributed to Any Store         | Medium    | https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/ |
| 8  | Maximum Candies Allocated to K Children                        | Medium    | https://leetcode.com/problems/maximum-candies-allocated-to-k-children/ |

---

## 7. Practice Tips

### How to recognize this pattern:

- The problem asks for a minimum or maximum possible value (e.g., minimum speed, maximum allocation).
- You can write a function to check if a guess is feasible.
- The feasibility function is monotonic—once it works, it keeps working for higher/lower values.

### Aha! Moments:

- Realizing you don’t need to simulate every possible answer—just check the boundaries and use binary search.
- Understanding that the condition function is the real heart of the solution.

### Debugging Tips:

- Double-check your condition function—off-by-one errors are common.
- Make sure your search space boundaries are correct (min/max possible values).
- Test edge cases: smallest/largest inputs, one day, one item, etc.

### Memory Tricks:

- Remember: "Binary search on answer" = "Guess, check, and adjust."
- Mnemonic: Condition Function = Can Find (the answer).

By mastering the Binary Search on Answer/Condition Function pattern, you’ll unlock a powerful tool for tackling a wide range of optimization problems—especially those loved by top tech companies like Amazon, Google, Facebook, and Flipkart!

