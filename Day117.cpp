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

void preOrder(Node *root)
{
    if (root == NULL)
    {
        cout << endl;
        return;
    }
    // N L R

    // N
    cout << root->data << " ";
    // L
    preOrder(root->left);
    // R
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // L N R

    // L
    inOrder(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // L R N

    // L
    postOrder(root->left);
    // R
    postOrder(root->right);
    // N
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << front->data << " ";
        if (front->left != NULL)
        {
            q.push(front->left);
        }
        if (front->left != NULL)
        {
            q.push(front->right);
        }
    }
}

int main()
{
    Node *root = createTree();
    preOrder(root);
    return 0;
}