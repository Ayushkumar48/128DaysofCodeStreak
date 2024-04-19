// LeetCode

// 112. Path Sum
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
    bool solve(TreeNode *root, int targetSum, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        sum += (root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool left = solve(root->left, targetSum, sum);
        bool right = solve(root->right, targetSum, sum);
        return left || right;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};

// 113. Path Sum II
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        sum += (root->val);
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                ans.push_back(temp);
                return;
            }
            else
            {
                return;
            }
        }
        solve(root->left, targetSum, sum, temp, ans);
        solve(root->right, targetSum, sum, temp, ans);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }
};
