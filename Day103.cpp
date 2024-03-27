// LeetCode

// 25. Reverse Nodes in k-Group
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
    pair<ListNode *, ListNode *> reversed(ListNode *head)
    {
        ListNode *dH = new ListNode(501, head);
        ListNode *nextNode = head->next, *curr = head;
        stack<ListNode *> st;
        while (curr->next != NULL)
        {
            curr->next = NULL;
            st.push(curr);
            curr = nextNode;
            nextNode = nextNode->next;
        }
        st.push(curr);
        curr = dH;
        while (!st.empty())
        {
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        pair<ListNode *, ListNode *> p;
        p.first = dH->next;
        p.second = curr;
        dH->next = NULL;
        delete dH;
        return p;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dH = new ListNode(-1, head);
        ListNode *temp = dH;
        while (temp != NULL && temp->next != NULL)
        {
            ListNode *left = temp;
            ListNode *node = temp->next;
            temp->next = NULL;
            temp = node;
            int i = 1;
            while (i < k)
            {
                if (temp->next == NULL)
                {
                    left->next = node;
                    return dH->next;
                }
                temp = temp->next;
                i++;
            }
            ListNode *right = temp->next;
            temp->next = NULL;
            pair<ListNode *, ListNode *> p = reversed(node);
            left->next = p.first;
            p.second->next = right;
            temp = p.second;
        }
        head = dH->next;
        dH->next = NULL;
        delete dH;
        return head;
    }
};

// 713. Subarray Product Less Than K
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int i = 0;
        int ans = 0;
        int product = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            product *= nums[j];
            while (i <= j && product >= k)
            {
                product /= nums[i];
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
};