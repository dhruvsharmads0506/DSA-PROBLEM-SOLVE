/*************************************************************
 * Project Title : Binary Search Tree (BST) Implementation
 * Language      : C++
 * Author        : Dhruv Sharma
 * Date Created  : November 11, 2025
 * Last Modified : November 11, 2025
 * 
 * Description:
 * This program implements a Binary Search Tree (BST) in C++ 
 * with essential operations such as insertion, deletion, and
 * various tree traversals (InOrder, PreOrder, PostOrder, LevelOrder).
 * 
 * It also includes functions to find the minimum and maximum 
 * elements in the BST. Each function is documented with 
 * time and space complexity for clarity and interview readiness.
 *************************************************************/




#include <iostream>
#include <queue>
using namespace std;

// =============================================================
// 🧩 CLASS: Node
// Represents a single node of the Binary Search Tree
// =============================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// =============================================================
// 🌱 FUNCTION: insertIntoBST
// Inserts a new node with value `d` into the BST.
// Time Complexity: O(log n) [for balanced tree], O(n) [worst case - skewed tree]
// Space Complexity: O(h) [recursive stack, h = height of tree]
// =============================================================
Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    else
        root->left = insertIntoBST(root->left, d);

    return root;
}

// =============================================================
// ⌨️ FUNCTION: takeInput
// Continuously takes user input and inserts values into BST
// Input terminates when -1 is entered.
// Time Complexity: O(n log n) [for n insertions]
// Space Complexity: O(n) [for recursion + nodes]
// =============================================================
void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// =============================================================
// 🧭 FUNCTION: levelOrderTraversal
// Prints BST level by level using a queue.
// Time Complexity: O(n)
// Space Complexity: O(n)
// =============================================================
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

// =============================================================
// 🔁 FUNCTION: PreOrder Traversal
// Visit: Root → Left → Right
// Time Complexity: O(n)
// Space Complexity: O(h)
// =============================================================
void PreOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// =============================================================
// 🔁 FUNCTION: InOrder Traversal
// Visit: Left → Root → Right
// Produces a sorted sequence for BST.
// Time Complexity: O(n)
// Space Complexity: O(h)
// =============================================================
void InOrder(Node* root) {
    if (root == NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// =============================================================
// 🔁 FUNCTION: PostOrder Traversal
// Visit: Left → Right → Root
// Time Complexity: O(n)
// Space Complexity: O(h)
// =============================================================
void PostOrder(Node* root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

// =============================================================
// 🔍 FUNCTION: minVal
// Finds the node with the minimum value in the BST.
// Time Complexity: O(h)
// Space Complexity: O(1)
// =============================================================
Node* minVal(Node* root) {
    Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

// =============================================================
// 🔍 FUNCTION: maxVal
// Finds the node with the maximum value in the BST.
// Time Complexity: O(h)
// Space Complexity: O(1)
// =============================================================
Node* maxVal(Node* root) {
    Node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

// =============================================================
// ❌ FUNCTION: deleteFromBST
// Deletes a node with value `val` from the BST.
// Handles all 3 cases:
// 1. Node with 0 child
// 2. Node with 1 child
// 3. Node with 2 children (replace with inorder successor)
// Time Complexity: O(h)
// Space Complexity: O(h)
// =============================================================
Node* deleteFromBST(Node* root, int val) {
    if (root == NULL)
        return root;

    if (root->data == val) {
        // Case 1: 0 children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2a: Only left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2b: Only right child
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Two children
        int mini = minVal(root->right)->data;
        root->data = mini;
        root->right = deleteFromBST(root->right, mini);
        return root;
    } 
    else if (val > root->data) {
        root->right = deleteFromBST(root->right, val);
        return root;
    } 
    else {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
}

// =============================================================
// 🧾 MAIN FUNCTION
// Demonstrates BST creation, traversals, and deletion.
// =============================================================
int main() {
    Node* root = NULL;

    cout << "Enter data to create BST (-1 to stop): " << endl;
    takeInput(root);

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nPreOrder Traversal:\n";
    PreOrder(root);
    cout << endl;

    cout << "\nInOrder Traversal:\n";
    InOrder(root);
    cout << endl;

    cout << "\nPostOrder Traversal:\n";
    PostOrder(root);
    cout << endl;

    cout << "\nMinimum value in BST: " << minVal(root)->data << endl;
    cout << "Maximum value in BST: " << maxVal(root)->data << endl;

    int val;
    cout << "\nEnter value to delete from BST: ";
    cin >> val;
    root = deleteFromBST(root, val);

    cout << "\nInOrder Traversal after deletion:\n";
    InOrder(root);
    cout << endl;

    return 0;
}
