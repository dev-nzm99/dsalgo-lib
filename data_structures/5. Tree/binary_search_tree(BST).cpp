/*
* Created: 2025-12-29 14:15
* Author:
   __    __   ______    ________  __      __  __    __  __
  /  |  /  | /      |  /       / /  |    /  |/  |  /  |/  |
  $$ |  $$ |/$$$$$$  |$$$$$$$$/ $$  |   /$$ |$$ |  $$ |$$ |
  $$$   $$ |$$ |__$$ |    /$$/  $$$    /$$$ |$$ |  $$ |$$ |
  $$$$  $$ |$$    $$ |   /$$/   $$$$  /$$$$ |$$ |  $$ |$$ |
  $$ $$ $$ |$$$$$$$$ |  /$$/    $$ $$ $$/$$ |$$ |  $$ |$$ |
  $$ |$$$$ |$$ |  $$ | /$$/____ $$  $$$/ $$ |$$ |  $$ |$$ |_____
  $$ | $$$ |$$ |  $$ |/$$/     |$$   $/  $$ |$$    $$/ $$       |
  $$/   $$/ $$/   $$ /$$$$$$$$/ $$/      $$/  $$$$$$/  $$$$$$$$/
*/
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *left, *right;
    Node(int value){
        this->value = value;
        left = right = NULL;
    }
};

class BinarySearchTree
{
private:
    Node *root;

    // Helper function to insert a node in the tree
    Node *insertNode(Node *node, int val){
        if (node == NULL){
            return new Node(val);
        }
        if (val < node->value){
            node->left = insertNode(node->left, val);
        }
        else{
            node->right = insertNode(node->right, val);
        }
        return node;
    }

    // Helper function to search for a value in the tree
    bool searchNode(Node *node, int val){
        if (node == NULL){
            return false;
        }
        if (node->value == val){
            return true;
        }
        if (val < node->value){
            return searchNode(node->left, val);
        }
        else{
            return searchNode(node->right, val);
        }
    }

    // Helper function to delete the tree and free memory
    void deleteTree(Node *node){
        if (node == NULL){
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    // In-Order Traversal (Left, Root, Right)
    void inOrderTraversal(Node *node){
        if (node == NULL)
            return;

        inOrderTraversal(node->left);  // Traverse left subtree
        cout << node->value << " ";    // Visit the node
        inOrderTraversal(node->right); // Traverse right subtree
    }

    // Pre-Order Traversal (Root, Left, Right)
    void preOrderTraversal(Node *node){
        if (node == NULL)
            return;

        cout << node->value << " ";     // Visit the node
        preOrderTraversal(node->left);  // Traverse left subtree
        preOrderTraversal(node->right); // Traverse right subtree
    }

    // Post-Order Traversal (Left, Right, Root)
    void postOrderTraversal(Node *node){
        if (node == NULL)
            return;

        postOrderTraversal(node->left);  // Traverse left subtree
        postOrderTraversal(node->right); // Traverse right subtree
        cout << node->value << " ";      // Visit the node
    }
    void level_order_traversal(Node *root, vector<int> &ans){
        queue<Node *> q;
        q.push(root);
        while (!q.empty()){
            Node *treeNode = q.front();
            q.pop();
            ans.push_back(treeNode->value);
            if (treeNode->left != NULL){
                q.push(treeNode->left);
            }
            if (treeNode->right != NULL){
                q.push(treeNode->right);
            }
        }
    }

public:
    // Constructor to initialize the root as nullptr
    BinarySearchTree(){
        root = NULL;
    }

    // Destructor to clean up memory (Need only in case of C++)
    ~BinarySearchTree(){
        deleteTree(root);
    }

    // Function to insert a new node into the tree
    void insert(int val){
        root = insertNode(root, val);
    }

    // Function to search for a value in the tree
    bool search(int val){
        return searchNode(root, val);
    }

    // Function to perform Pre-Order Traversal
    void preOrder(){
        preOrderTraversal(root);
        cout << "\n";
    }

    // Function to perform In-Order Traversal
    void inOrder(){
        inOrderTraversal(root);
        cout << "\n";
    }

    // Function to perform Post-Order Traversal
    void postOrder(){
        postOrderTraversal(root);
        cout << "\n";
    }
    void levelOrderTraversal(){
        vector<int> res = {};
        level_order_traversal(root, res);
        for (const auto &nodeVal : res){
            cout << nodeVal << " ";
        }
        cout << "\n";
    }
};

int main(){
    BinarySearchTree tree;
    vector<int> val = {5, 4, 7, 3, 8, 6};
    for (const auto &x : val){
        tree.insert(x);
    }

    cout << "Inorder: ";
    tree.inOrder(); // Inorder traversal
    cout << "Preorder: ";
    tree.preOrder(); // Preorder traversal
    cout << "Postorder: ";
    tree.postOrder();        // Postorder traversal
    cout << "Label order: "; // Label order traversal
    tree.levelOrderTraversal();

    return 0;
}

/*-------------------------------------------------
Output:
Inorder: 3 4 5 6 7 8
Preorder: 5 4 3 7 6 8
Postorder: 3 4 6 8 7 5
Label order: 5 4 7 3 6 8 
*/
