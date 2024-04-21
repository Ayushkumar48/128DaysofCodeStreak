#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BSTNode
{
public:
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
BSTNode *insertIntoBST(BSTNode *root, int data)
{
    if (root == NULL)
    {
        root = new BSTNode(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void createBST(BSTNode *&root)
{
    cout << "Enter data:"
         << "\n";
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data:"
             << "\n";
        cin >> data;
    }
}
void BSTLevelOrder(BSTNode *root)
{
    queue<BSTNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BSTNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
BSTNode *minValue(BSTNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    BSTNode *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
BSTNode *maxValue(BSTNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    BSTNode *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
bool searchInBST(BSTNode *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (root->data < target)
    {
        return searchInBST(root->right, target);
    }
    return searchInBST(root->left, target);
}
BSTNode *deleteFromBST(BSTNode *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->left == NULL)
        {
            BSTNode *childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            BSTNode *childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        else
        {
            // max value of left subtree or min value of right subtree
            BSTNode *maxi = maxValue(root->left);
            root->data = maxi->data;
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        root->left = deleteFromBST(root->left, target);
    }
    else
    {
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}
int main()
{
    BSTNode *root = NULL;
    createBST(root);
    BSTLevelOrder(root);
    BSTNode *minRoot = minValue(root);
    if (minRoot == NULL)
    {
        cout << "No min value";
    }
    else
    {
        cout << minRoot->data;
    }
    bool found = searchInBST(root, 55);
    cout << found;
    root = deleteFromBST(root, 90);
    BSTLevelOrder(root);
    return 0;
}