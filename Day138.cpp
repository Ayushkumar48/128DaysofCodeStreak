// LeetCode

// 154. Find Minimum in Rotated Sorted Array II
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1;
        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] > nums[e])
            {
                s = m + 1;
            }
            else if (nums[m] < nums[e])
            {
                e = m;
            }
            else
            {
                e--;
            }
        }
        return nums[s];
    }
};

// 222. Count Complete Tree Nodes
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
    void inOrder(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left, ans);
        ans += 1;
        inOrder(root->right, ans);
    }
    int countNodes(TreeNode *root)
    {
        int x = 0;
        inOrder(root, x);
        return x;
    }
};

// 2816. Double a Number Represented as a Linked List
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
    ListNode *doubleIt(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->next;
        }
        bool flag = false;
        head = st.top();
        head->next = NULL;
        st.pop();
        head->val *= 2;
        if (head->val > 9)
        {
            flag = true;
            head->val -= 10;
        }
        while (!st.empty())
        {
            st.top()->next = head;
            head = st.top();
            st.pop();
            int num = head->val * 2;
            if (flag)
            {
                num += 1;
                flag = false;
            }
            if (num > 9)
            {
                num -= 10;
                flag = true;
            }
            head->val = num;
        }
        if (flag)
        {
            ListNode *newNode = new ListNode(1, head);
            head = newNode;
        }
        return head;
    }
};