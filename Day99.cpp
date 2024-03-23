// LeetCode

// 143. Reorder List
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
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        ListNode *dH = new ListNode(100, head);
        ListNode *prev = dH;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        prev = slow;
        slow = slow->next;
        stack<ListNode *> st;
        while (slow != NULL)
        {
            prev->next = NULL;
            st.push(prev);
            prev = slow;
            slow = slow->next;
        }
        st.push(prev);
        slow = head;
        while (slow != NULL)
        {
            fast = slow->next;
            slow->next = st.top();
            slow = slow->next;
            slow->next = fast;
            prev = slow;
            slow = slow->next;
            st.pop();
        }
        if (!st.empty())
        {
            prev->next = st.top();
            st.pop();
        }
    }
};

// 92. Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int s, int e)
    {
        if (head == NULL || head->next == NULL || s == e)
        {
            return head;
        }
        ListNode *dH = new ListNode(501, head);
        ListNode *prev = dH;
        ListNode *curr = head;
        int i = 1;
        while (i != s)
        {
            curr = curr->next;
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        ListNode *left = prev;
        prev = dH;
        prev->next = curr;
        while (i != e)
        {
            curr = curr->next;
            prev = prev->next;
            i++;
        }
        curr = curr->next;
        prev = prev->next;
        prev->next = NULL;
        ListNode *right = curr;
        curr = dH->next;
        dH->next = NULL;
        pair<ListNode *, ListNode *> p = reversed(curr);
        left->next = p.first;
        p.second->next = right;
        if (s == 1)
        {
            return dH->next;
        }
        delete dH;
        return head;
    }
};