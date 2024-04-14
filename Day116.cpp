// Today I learned about a new data structure, Trees.
// Tree is a non linear data structure. All the data in the tree is in the form of hierarchy.
// A tree is made up of collection of nodes such that each node of the tree stores a value and a list of references to other nodes or the children.
// Some examples are Generic Tree, Binary Tree, Binary Search Tree, Trie, AVL Tree, Red-Black Tree, etc.

// Some terminologies:-
// Parent Node: The node which is a predecessor of a node is called the parent node of that node.
// Child Node: The node which is the immediate successor of a node is called the child node of that node.
// Root Node: The topmost node of a tree or the node which does not have any parent node is called the root node. A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.
// Leaf Node or External Node: The nodes which do not have any child nodes are called leaf nodes.
// Ancestor of a Node: Any predecessor nodes on the path of the root to that node are called Ancestors of that node.
// Descendant: A node x is a descendant of another node y if and only if y is an ancestor of y. Opposite of ancestor.
// Sibling: Children of the same parent node are called siblings.
// Level of a node: The count of edges on the path from the root node to that node. The root node has level 0.
// Internal node: A node with at least one child is called Internal Node.
// Neighbour of a Node: Parent or child nodes of that node are called neighbors of that node.
// Subtree: Any node of the tree along with its descendant.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the value for this node:" << endl;
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    Node *newNode = new Node(n);
    cout << "Left of node:" << newNode->data << endl;
    newNode->left = createTree();

    cout << "Right of node:" << newNode->data << endl;
    newNode->right = createTree();
    return newNode;
}

int main()
{
    Node *root = createTree();
    return 0;
}