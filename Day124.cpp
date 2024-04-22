// LeetCode

// 98. Validate Binary Search Tree
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
    bool solve(TreeNode *root, long lowerBound, long upperBound)
    {
        if (root == NULL)
        {
            return true;
        }
        bool a = (root->val > lowerBound);
        bool b = (root->val < upperBound);
        bool c = solve(root->left, lowerBound, root->val);
        bool d = solve(root->right, root->val, upperBound);
        if (a && b && c && d)
        {
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode *root)
    {
        long lowerBound = LONG_MIN;
        long upperBound = LONG_MAX;

        bool ans = solve(root, lowerBound, upperBound);
        return ans;
    }
};

// 235. Lowest Common Ancestor of a Binary Search Tree
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
        if (root == NULL || p == NULL || q == NULL)
        {
            return NULL;
        }

        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

// 230. Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode *root, int &k)
    {
        if (root == NULL)
        {
            return -1;
        }
        // InOrder Traversal
        // L N R
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
        {
            return leftAns;
        }
        k--;
        if (k == 0)
        {
            return root->val;
        }
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};

// 653. Two Sum IV - Input is a BST
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
    void storeInOrder(TreeNode *root, vector<int> &inOrder)
    {
        if (root == NULL)
        {
            return;
        }
        storeInOrder(root->left, inOrder);
        inOrder.push_back(root->val);
        storeInOrder(root->right, inOrder);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inOrder;
        storeInOrder(root, inOrder);
        int s = 0;
        int e = inOrder.size() - 1;
        while (s < e)
        {
            int sum = inOrder[s] + inOrder[e];
            if (sum == k)
            {
                return true;
            }
            if (sum > k)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        return false;
    }
};

// 148. Sort List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        vector<pair<int, ListNode *>> v;
        ListNode *temp = head;
        while (temp != NULL)
        {
            pair<int, ListNode *> p = {temp->val, temp};
            v.push_back(p);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        temp = v[v.size() - 1].second;
        temp->next = NULL;
        v.pop_back();
        while (v.size() > 0)
        {
            ListNode *temp2 = v[v.size() - 1].second;
            temp2->next = temp;
            temp = temp2;
            v.pop_back();
        }
        return temp;
    }
};