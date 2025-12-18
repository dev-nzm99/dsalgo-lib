# Binary Search Patterns Overview

Binary Search is a powerful algorithmic technique used to efficiently find elements or answers in sorted data. The following overview categorizes the most common binary search sub-patterns, their core ideas, and when to apply them.

<p align="center">
  <img src="https://github.com/dev-nzm99/DSA-Pathshala/blob/main/src/img/Binary_search.png" alt="Binary Search Illustration" width = "80%">
</p>

---

## [1. Binary Search Patterns: On Sorted Array/List](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Binary%20Search%20Patterns/Binary%20Search%20Patterns%3A%20On%20Sorted%20Array)

**Overview:**

* Search for a specific element in a sorted array/list.
* Efficiently reduces search space by half with each comparison.

**Use Cases:**

* Find an element in a sorted array.
* Determine if an element exists in a sorted list.
* Find the index of a target element.

**Key Idea:**

* Use binary search to minimize the time complexity to O(log n) by eliminating half of the search space at each step.

**Example Problems:**

* Binary Search
* Search Insert Position
* Find Peak Element

---

## [2. Binary Search Patterns: On Answer / Condition Function](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Binary%20Search%20Patterns/Binary%20Search%20Patterns%3A%20On%20Answer%20or%20Condition%20Function)

**Overview:**

* Instead of searching through data, search through possible answers or conditions.
* This allows you to find the optimal value or solution by reducing the range of answers.

**Use Cases:**

* Find the minimum or maximum value that satisfies a condition.
* Solve problems like finding the smallest/largest possible value that meets certain criteria.

**Key Idea:**

* Use binary search to narrow down the potential answers by testing different conditions.

**Example Problems:**

* Minimize Max Distance to Gas Station
* Split Array Largest Sum
* Find K Closest Elements

---

## [3. Binary Search Patterns: Median and Kth of Two Sorted Arrays](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Binary%20Search%20Patterns/Binary%20Search%20Patterns%3A%20Median%20and%20Kth%20of%20Two%20Sorted%20Arrays)

**Overview:**

* Find the median or k-th smallest element from two sorted arrays.
* This pattern helps in searching order statistics across multiple sorted arrays.

**Use Cases:**

* Find the median of two sorted arrays.
* Find the k-th smallest element in a sorted matrix.

**Key Idea:**

* Use binary search to partition the arrays in a way that allows you to find the desired element without merging them.

**Example Problems:**

* Median of Two Sorted Arrays
* Kth Smallest Element in a Sorted Matrix
* Find Kth Smallest Pair Distance

---

## [4. Binary Search Patterns: Find Min/Max in Rotated Sorted Array](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Binary%20Search%20Patterns/Binary%20Search%20Patterns%3A%20Find%20Min-Max%20in%20Rotated%20Sorted%20Array)

**Overview:**

* Search for the minimum or maximum value in a rotated sorted array.
* The array is sorted but then rotated, which introduces an element of complexity.

**Use Cases:**

* Find the minimum or maximum element in a rotated sorted array.
* Identify the rotation point in a rotated array.

**Key Idea:**

* Use binary search to find the pivot point or smallest element, reducing search space efficiently.

**Example Problems:**

* Find Minimum in Rotated Sorted Array
* Search in Rotated Sorted Array

---

## [5. Binary Search Patterns: Find First/Last Occurrence](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Binary%20Search%20Patterns/Binary%20Search%20Patterns%3A%20Find%20First%20or%20Last%20Occurrence)

**Overview:**

* Use binary search to find the first or last occurrence of an element in a sorted array.
* Useful when multiple occurrences of an element are possible.

**Use Cases:**

* Find the first or last position of a target in a sorted array.
* Find the range of occurrences of an element.

**Key Idea:**

* Modify binary search to continue searching even after finding the target, depending on whether you’re looking for the first or last occurrence.

**Example Problems:**

* Find First and Last Position of Element in Sorted Array
* Find K Closest Elements
* Count of Smaller Numbers After Self

