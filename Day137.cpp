// LeetCode

// 162. Find Peak Element
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        // bool flag = false;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (m > 0 && nums[m - 1] > nums[m])
            {
                e = m - 1;
            }
            else if (m < n - 1 && nums[m + 1] > nums[m])
            {
                s = m + 1;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }
};

// 2487. Remove Nodes From Linked List
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
    ListNode *removeNodes(ListNode *head)
    {
        vector<ListNode *> lists;
        ListNode *temp = head;
        while (temp != NULL)
        {
            lists.push_back(temp);
            temp = temp->next;
        }
        int maxi = 0;
        for (int i = lists.size() - 1; i >= 0; i--)
        {
            ListNode *curr = lists[i];
            if (curr->val >= maxi)
            {
                maxi = curr->val;
            }
            else
            {
                lists[i] = NULL;
            }
        }
        ListNode *dummyNode = new ListNode(-1);
        temp = dummyNode;
        for (auto it : lists)
        {
            if (it != NULL)
            {
                temp->next = it;
                temp = temp->next;
            }
        }
        temp->next = NULL;
        return dummyNode->next;
    }
};