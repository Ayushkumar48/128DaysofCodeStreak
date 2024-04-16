// LeetCode

// 104. Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int ans1 = maxDepth(root->left);
        int ans2 = maxDepth(root->right);
        return max(ans1, ans2) + 1;
    }
};

// 543. Diameter of Binary Tree
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
            return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);
        int height = 1 + max(left_height, right_height);

        return height;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int a = diameterOfBinaryTree(root->left);
        int b = diameterOfBinaryTree(root->right);
        int c = height(root->left) + height(root->right);
        return max(a, max(b, c));
    }
};