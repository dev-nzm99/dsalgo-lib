# Array/Matrix Manipulation Patterns  
## Subpattern: In-place Rotation

---

## Pattern Overview

In-place rotation is a technique used to rearrange elements in an array or a 2D matrix by a specific number of steps or degrees. This method modifies the original data structure directly instead of creating a new copy to store the result.

Use this pattern when you need to change the order or orientation of data while minimizing memory usage. It is essential for systems with limited resources or when working with very large datasets where allocating extra space is inefficient.

### Examples
- Rotating a square image matrix 90 degrees in photo editing software.  
- Shifting elements in a circular buffer to manage a fixed-size data stream.  
- Cycling through a list of active tasks in a round-robin scheduler.  
- Reorganizing a grid-based game board after a player move.  

This pattern provides a significant advantage by achieving **O(1) space complexity** since it uses no extra memory. The time complexity is typically **O(n)** for arrays or **O(n²)** for matrices, as each element is moved to its final position once.

---

## Pattern Overview Diagram

*(Diagram placeholder)*

---

# Core Concepts

Let's break down the key ideas behind **in-place rotation**.

---

## Two Pointers

Think of two fingers pointing at different spots in your array or matrix. You use them to swap or reverse elements, moving data around efficiently without needing extra storage.

---

## Array/Matrix Structure

- **Array:** A single row of elements, like a line of people.  
- **Matrix:** A grid (rows and columns), like seats in a theater.

---

## In-place Operations

“In-place” means you modify the original data structure, not creating a new one. Imagine rearranging chairs in a room without bringing in more chairs.

---

## Reversal Technique (for arrays)

To rotate an array, you can:

1. Reverse the whole array.  
2. Reverse the first part.  
3. Reverse the second part.  

This clever trick lets you rotate with just a few swaps.

---

## Layer-by-Layer Rotation (for matrices)

For a matrix, think of peeling an onion: rotate the outermost layer, then move inward, rotating each layer.

---

# Time and Space Complexity

- **Time Complexity:**  
  - `O(n)` for arrays (n = number of elements)  
  - `O(n²)` for matrices (since you process each cell)

- **Space Complexity:**  
  - `O(1)` since you don't use extra arrays—just a few variables.

---

# Math Connection

Rotation often involves **modular arithmetic**.

Example:
