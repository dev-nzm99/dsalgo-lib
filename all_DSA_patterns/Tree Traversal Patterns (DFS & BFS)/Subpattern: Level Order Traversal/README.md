# Tree Traversal Patterns (DFS & BFS)

## Subpattern: Level Order Traversal

## 1. Pattern Overview
Imagine you’re at a family reunion, and you want to take a group photo of everyone by generation: grandparents first, then their children, then grandchildren, and so on. You’d line up each generation together, moving from the oldest to the youngest. Level Order Traversal in trees works exactly like this: you visit all nodes at one level before moving to the next.

In computer science, this pattern is especially useful when you need to process a tree layer by layer. For example, if you want to find the shortest path in a tree, or analyze how data is distributed across levels, level order traversal is your go-to tool. It’s like reading a book chapter by chapter, rather than flipping randomly between pages.

This approach is commonly used in scenarios like:

- Printing a tree in a human-friendly way (one level at a time)
- Finding the largest value at each level (like picking the tallest person in each generation)
- Calculating sums or statistics per level
- Visualizing what you’d see if you looked at a tree from the side (e.g., right side view)

Level order traversal is a classic example of Breadth-First Search (BFS), and it’s a favorite topic in interviews at companies like Google, Amazon, and Microsoft. Mastering this pattern helps you break down complex tree problems into manageable, logical steps.

---

## 2. Core Concepts
Let’s break down the core ideas behind level order traversal:

- **Breadth-First Search (BFS):**  
Instead of diving deep into one branch (like Depth-First Search), BFS explores all nodes at the current depth before moving deeper. Think of it as exploring all rooms on one floor of a building before taking the stairs to the next.

- **Queue Data Structure:**  
BFS relies on a queue, which works like a line at a ticket counter: first in, first out. When you visit a node, you add its children to the end of the queue, ensuring you process nodes in the correct order.

- **Layer-by-Layer Processing:**  
At each step, you process all nodes currently in the queue (i.e., all nodes at the current level), then enqueue their children. This guarantees you’re always working one level at a time.

- **Time Complexity:**  
Every node is visited once, and each child is enqueued and dequeued once. So, for a tree with N nodes, the time complexity is **O(N)**.  
Analogy: Like reading every page of a book exactly once.

- **Space Complexity:**  
The queue can hold up to the maximum number of nodes at any level (the tree’s maximum width). In a balanced binary tree, this is about half the nodes at the bottom level, so space complexity is **O(W)** where **W** is the maximum width.

- **Mathematical Foundation:**  
BFS leverages the idea of traversing graphs in "waves" or "layers." In trees, this naturally aligns with levels, making it perfect for problems that require per-level analysis.

- **Practical Understanding:**  
Whenever you need to group, summarize, or compare nodes by their depth in the tree, level order traversal is your friend.

---

## 3. Implementation Approach
Let’s build a mental model for solving level order traversal problems:

**Think Like This:**
- "I need to process the tree one level at a time."
- "I want to visit all nodes at depth 1, then depth 2, then depth 3, etc."
- "I should use a queue to keep track of which nodes to visit next."

**Step-by-Step Approach:**
1. Start with the root node.  
   If the tree is empty, return an empty result.

2. Initialize a queue.  
   Place the root node in the queue.

3. While the queue is not empty:  
   a. Determine the number of nodes at the current level (queue size).  
   b. For each node at this level:
   - Remove it from the queue.
   - Record its value (for output, sum, max, etc.).
   - Add its left and right children (if they exist) to the queue.

4. After processing all nodes at the current level:
   - Store the results for this level (e.g., as a list or sum).
   - Repeat until the queue is empty.

**Decision Tree:**
- Do you need to process nodes by level?  
  Use BFS with a queue.
- Do you need to process nodes in zigzag order?  
  Alternate the order you add nodes to your result.
- Do you need to find values visible from the side?  
  Only record the last node at each level.

**Edge Cases:**
- Empty tree: Return an empty list.
- Single node: Only one level, so output is just the root.
- Unbalanced tree: The queue will naturally handle this; some levels may have fewer nodes.

**Everyday Example:**
Imagine you’re organizing a relay race where runners pass the baton to the next generation. You want to record who runs in each round. Level order traversal helps you keep track of each group as they take their turn.

---

## 4. C++ Code Example
Let’s implement Binary Tree Level Order Traversal (from the database):
```C++ []
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
 * Function to perform level order traversal of a binary tree.
 * Returns a vector of vectors, where each inner vector contains
 * the values of nodes at that level.
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result; // Final answer: each subvector is a level
    if (!root) return result;   // Edge case: empty tree

    queue<TreeNode*> q;         // Queue for BFS
    q.push(root);               // Start with the root node

    while (!q.empty()) {
        int levelSize = q.size();           // Number of nodes at current level
        vector<int> currentLevel;           // Stores values for this level

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();     // Get next node in queue
            q.pop();

            currentLevel.push_back(node->val); // Record node's value

            // Add children to queue for next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevel);     // Save this level's values
    }
    return result;
}
```
### **Key Points in the Code:**

- The queue ensures nodes are processed in left-to-right, level-by-level order.
- levelSize is crucial: it tells us how many nodes are at the current level, so we don’t mix levels.
- After processing each level, we add the collected values to the result.
