// LeetCode

// 236. Lowest Common Ancestor of a Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p)
        {
            return p;
        }
        if (root == q)
        {
            return q;
        }
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
        if (leftAns == NULL && rightAns == NULL)
        {
            return NULL;
        }
        if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else
        {
            return root;
        }
    }
};

// 110. Balanced Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int a = height(root->left);
        int b = height(root->right);
        return max(a, b) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        int left = height(root->left);
        int right = height(root->right);
        int diff = abs(left - right);
        bool currNode = (diff <= 1);
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        if (currNode && leftAns && rightAns)
        {
            return true;
        }
        return false;
    }
};