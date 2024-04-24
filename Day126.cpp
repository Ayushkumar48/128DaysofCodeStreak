// LeetCode

// 215. Kth Largest Element in an Array
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int j = k; j < nums.size(); j++)
        {
            if (nums[j] > pq.top())
            {
                pq.pop();
                pq.push(nums[j]);
            }
        }
        return pq.top();
    }
};

// 958. Check Completeness of a Binary Tree
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
    bool levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
            {
                flag = true;
            }
            else
            {
                if (flag)
                {
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode *root)
    {
        return levelOrderTraversal(root);
    }
};

// 23. Merge k Sorted Lists
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
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *listHead = lists[i];
            if (listHead != NULL)
            {
                pq.push(listHead);
            }
        }
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (!pq.empty())
        {
            ListNode *topNode = pq.top();
            pq.pop();
            if (head == NULL)
            {
                head = topNode;
                tail = topNode;
                if (tail->next != NULL)
                {
                    pq.push(tail->next);
                }
            }
            else
            {
                tail->next = topNode;
                tail = topNode;
                if (tail->next != NULL)
                {
                    pq.push(tail->next);
                }
            }
        }
        return head;
    }
};