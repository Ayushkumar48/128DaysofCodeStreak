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
        if (front->right != NULL)
        {
            q.push(front->right);
        }
    }
}

void createMapping(vector<int> inOrder, unordered_map<int, int> &ump, int size)
{
    for (int i = 0; i < size; i++)
    {
        ump[inOrder[i]] = i;
    }
}

Node *createATree(vector<int> &inOrder, vector<int> &preOrder, int &preOrderIndex, int inOrderStart, int inOrderEnd, int size, unordered_map<int, int> &ump)
{
    if (preOrderIndex >= size || inOrderStart >= inOrderEnd)
    {
        return NULL;
    }
    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    Node *root = new Node(element);
    int position = ump[element];
    root->left = createATree(inOrder, preOrder, preOrderIndex, inOrderStart, position - 1, size, ump);
    root->right = createATree(inOrder, preOrder, preOrderIndex, position + 1, inOrderEnd, size, ump);
    return root;
}

void printLeftView(Node *root, int level, vector<int> &leftView)
{
    if (root == NULL)
    {
        return;
    }
    if (level == leftView.size())
    {
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

void printTopView(Node *root)
{
    unordered_map<int, int> ump;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        Node *frontNode = p.first;
        int hd = p.second;
        if (ump.find(hd) == ump.end())
        {
            ump[hd] = frontNode->data;
        }
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    cout << "Printing Top View:"
         << "\n";
    for (auto it : ump)
    {
        cout << it.second << " ";
    }
}

int main()
{
    vector<int> inOrder = {10, 8, 6, 2, 4, 12};
    vector<int> preOrder = {2, 8, 6, 10, 4, 12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    unordered_map<int, int> ump;
    createMapping(inOrder, ump, size);
    Node *root = createATree(inOrder, preOrder, preOrderIndex, inOrderStart, inOrderEnd, size, ump);
    cout << "Printing tree"
         << "\n";
    levelOrderTraversal(root);
    vector<int> leftView;
    printLeftView(root, 0, leftView);
    for (auto it : leftView)
    {
        cout << it << " ";
    }
    printTopView(root);
    return 0;
}