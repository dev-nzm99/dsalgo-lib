# Tree Traversal Patterns (DFS & BFS)

## Subpattern: Recursive Postorder Traversal

## 1. Pattern Overview
Recursive Postorder Traversal is a Depth First Search (DFS) method. A node is processed only after its children have been visited. In a binary tree, the order of operations is left child, then right child, and finally the current node. This sequence ensures you process all subtrees before the parent node.

This pattern is used for bottom-up processing.

### Pattern Overview Diagram

<p align="center">
  <img src="https://thita.ai/pattern-svgs/tree_traversal_patterns_dfs_bfs_recursive_postorder_traversal.svg" alt="Recursive Postorder Traversal">
</p>

---

## 2. CORE CONCEPTS

### Breaking Down Postorder Traversal

#### Definition:
In postorder traversal, for each node, you:
1. Traverse the left subtree
2. Traverse the right subtree
3. Process the current node

#### Analogy:
Think of organizing a stack of nested boxes. You must unpack all the smaller boxes inside before you can deal with the outer box.

#

#### Recursive Nature:
Each call to the function handles a smaller subtree, trusting recursion to handle the rest.

> *“If I know how to process my children, I can process myself.”*

#

### Time and Space Complexity

#### Time Complexity:
Every node is visited exactly once, so for n nodes, it’s O(n)—like reading every page of a book in order.

#### Space Complexity:
The main space cost is the call stack due to recursion. In the worst case (a skewed tree), the stack can be as deep as the tree’s height, O(h). For a balanced tree, this is about O(log n).

---

## 3. Mathematical Foundations

- ### Divide and Conquer:
Postorder is a classic example of breaking a problem into smaller subproblems, solving them, and combining the results.

- ### Bottom-Up Processing:
Many problems (like finding the diameter or checking balance) require information from children before making decisions at the parent.

---

## 4. IMPLEMENTATION APPROACH

### Mental Model
Think recursively:

> *“For this node, I’ll trust recursion to handle the left and right children. Once they’re done, I’ll process myself.”*

##

### Step-by-Step Approach

#### Base Case:
If the current node is `nullptr` (empty), there’s nothing to do—return immediately.

#### Recursive Calls:
1. First, recursively process the left child.
2. Then, recursively process the right child.

#### Process Current Node:
After both children are done, perform the required action (e.g., add value to a result list, compute height, check balance).

##

### Decision Tree

### When to use postorder?
- Need to aggregate or compute something from children before acting on the parent? Use postorder.
- Need to delete nodes safely? Postorder ensures children are deleted before their parent.

##

### Edge Cases

- **Empty Tree:** The root is `nullptr`. Your function should handle this gracefully—often by returning a default value (like 0, true, or an empty list).
- **Single Node Tree:** The node has no children. Make sure your function still processes this node.
- **Unbalanced Trees:** The tree could be skewed (like a linked list). The recursion depth could become large—be mindful of stack overflow in extreme cases.

##

### Everyday Example

Think of organizing a family reunion. You need to call each family member, but only after you’ve spoken to all their children and grandchildren. This ensures you have all the family news before talking to the elders!

---

## 5. Practice Problems:

| #  | Problem                                               | Difficulty | LeetCode Link                                                                 |
|----|-------------------------------------------------------|------------|-------------------------------------------------------------------------------|
| 1  | Maximum Depth of Binary Tree                          | Easy       | [Link](https://leetcode.com/problems/maximum-depth-of-binary-tree/)          |
| 2  | Balanced Binary Tree                                  | Easy       | [Link](https://leetcode.com/problems/balanced-binary-tree/)                  |
| 3  | Binary Tree Maximum Path Sum                          | Hard       | [Link](https://leetcode.com/problems/binary-tree-maximum-path-sum/)          |
| 4  | Binary Tree Postorder Traversal                        | Easy       | [Link](https://leetcode.com/problems/binary-tree-postorder-traversal/)        |
| 5  | House Robber III                                      | Medium     | [Link](https://leetcode.com/problems/house-robber-iii/)                       |
| 6  | Find Leaves of Binary Tree                            | Medium     | [Link](https://leetcode.com/problems/find-leaves-of-binary-tree/)             |
| 7  | Diameter of Binary Tree                               | Easy       | [Link](https://leetcode.com/problems/diameter-of-binary-tree/)                |
| 8  | All Nodes Distance K in Binary Tree                   | Medium     | [Link](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)   |
| 9  | Delete Nodes And Return Forest                        | Medium     | [Link](https://leetcode.com/problems/delete-nodes-and-return-forest/)        |
| 10 | Height of Binary Tree After Subtree Removal Query     | Medium     | [Link](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-query/) |



---

## 6. PRACTICE TIPS

### Signals to Use This Pattern:
- The problem asks for information that depends on children before the parent (e.g., heights, sums, depths).
- You need to aggregate or combine results from subtrees.

---

### Common “Aha!” Moments:
- Realizing you can return extra information (like a boolean or height) up the recursion stack.
- Noticing that postorder naturally fits problems where parents depend on children.

---

### Debugging Tips:
- Print values as you return from recursion to see the order of processing.
- Watch for off-by-one errors in height calculations.

---

### Memory Tricks:
- “Left, Right, Root” = “Children before Parent.”
- Imagine “cleaning up” from the bottom up.

---

### Common Pitfall:
- Forgetting to process the current node after both children.
- Keep practicing with different tree shapes and edge cases. The more you see, the more intuitive postorder traversal becomes!
