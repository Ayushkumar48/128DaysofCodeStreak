// LeetCode

// 1019. Next Greater Node In Linked List
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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> nums;
        ListNode *temp = head;
        while (temp != NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> ans(nums.size());
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(nums[i]);
                ans[i] = 0;
                continue;
            }
            if (nums[i] >= st.top())
            {
                st.pop();
                while (!st.empty())
                {
                    if (nums[i] < st.top())
                    {
                        ans[i] = st.top();
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                if (st.empty())
                {
                    ans[i] = 0;
                }
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};