# Tree Traversal Patterns (DFS & BFS)
## Subpattern: Recursive Preorder Traversal

### 1. Pattern Overview
Imagine you’re exploring a family tree, starting at the oldest ancestor. You want to visit each person, but you always meet the parent first, then explore the left side of the family, and finally the right. This is the essence of recursive preorder traversal. In technical terms, it’s a way to visit every node in a tree by always processing the current node before its children—think of it as “parent, left, right.”

Why is this useful? Many real-world scenarios mirror this process. For example, consider organizing files on your computer: you look at a folder (the parent), then check its subfolders (left), and finally its files (right). Recursive preorder traversal is especially handy when you need to copy, print, or process the structure of a tree in a top-down manner—like generating all possible paths from the root to the leaves, or reconstructing a tree from traversal orders.

This pattern shines when you need to:

- Collect information from the root before diving deeper (e.g., building a path string).
- Clone or invert a tree structure.
- Compare two trees for equality.

In short, recursive preorder traversal is your go-to when you want to “visit and act” on each node before looking at its descendants, making it a foundational tool for tree-based problems.

### 2. Core Concepts
Let’s break down what’s happening in recursive preorder traversal:

#### Order of Operations:
- Visit the current node (do something with its value).
- Traverse the left subtree (recursively).
- Traverse the right subtree (recursively).

Think of it like reading a book chapter by chapter: you read the chapter title (the node), then the left section, then the right. This method is called “preorder” because you process the parent node before its children.

#### How Recursion Works:
Recursion is like giving yourself a to-do list: “For this node, do X, then repeat for the left and right children.” Each recursive call handles a smaller part of the tree, until you reach a node with no children (the base case).

#### Visualizing the Process:
Imagine a tree as a set of nested boxes. You open the top box (root), look inside (process), then open the left box, and so on. You never skip a box, and you always finish with one before moving to the next.

#### Time Complexity:
Every node is visited exactly once. So, for a tree with n nodes, the time complexity is O(n)—like reading every page in a book, one by one.

#### Space Complexity:
The space used depends on the tree’s height (the longest path from root to leaf). In the worst case (a skewed tree), recursion can use up to O(n) space (one call per node). In a balanced tree, it’s O(log n)—much less, because the tree is shorter.

#### Mathematical Foundation:
Preorder traversal is a depth-first search (DFS) variant. It’s systematic and guarantees that each node is handled in a predictable order, which is crucial for tasks like tree reconstruction or serialization.

### 3. Implementation Approach
Let’s build a mental model for recursive preorder traversal:

#### Think Like This:
- “At each node, what do I need to do before exploring its children?”
- “How do I break the problem into smaller, similar subproblems?”

#### Step-by-Step Approach:
1. **Base Case**:  
   If the current node is `nullptr` (empty), there’s nothing to do—return immediately. This prevents errors and stops recursion.

2. **Process the Node**:  
   Do whatever the problem asks for at this node. This could be:
   - Adding its value to a list (for traversal).
   - Building a string (for paths).
   - Comparing values (for tree equality).
   - Swapping children (for inversion).

3. **Recurse Left**:  
   Call the same function on the left child.

4. **Recurse Right**:  
   Call the same function on the right child.

#### Decision Tree:
- Do I need to process nodes in a specific order?  
   If “parent before children,” use preorder.
- Do I need to build or compare something as I go?  
   Preorder is ideal for constructing outputs that depend on the root first.

#### Handling Edge Cases:
1. **Empty Tree**:  
   Always check if the root is `nullptr` at the start.
   
2. **Single Node**:  
   Your code should handle trees with just one node (no children).
   
3. **Leaf Nodes**:  
   Special logic may be needed if you’re building paths or checking for leaves.

#### Example:
In the “Binary Tree Paths” problem, you start at the root, build up a path string, and whenever you hit a leaf, you record the path. The recursive call naturally builds and unwinds the path as you traverse.

#### Debugging Tip:
- Print the node value at each call to trace the traversal order.
- Use clear variable names like `currentPath` or `result` to track what you’re building.

