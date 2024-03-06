// LeetCode

// 237. Delete Node in a Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// 238. Product of Array Except Self
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        bool flag = false;
        int index;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 && flag == true)
            {
                return ans;
            }
            else if (nums[i] == 0)
            {
                index = i;
                flag = true;
            }
        }
        if (flag == true)
        {
            int product = 1;
            for (int i = 0; i < index; i++)
            {
                product *= nums[i];
            }
            if (index == nums.size() - 1)
            {
                ans[index] = product;
                return ans;
            }
            else
            {
                for (int i = index + 1; i < nums.size(); i++)
                {
                    product *= nums[i];
                }
                ans[index] = product;
                return ans;
            }
        }
        else
        {
            int wholeProduct = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                wholeProduct *= nums[i];
            }
            for (int i = 0; i < nums.size(); i++)
            {
                ans[i] = wholeProduct / nums[i];
            }
        }
        return ans;
    }
};