// LeetCode

// 82. Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        unordered_map<int, int> ump;
        ListNode *temp = head;
        while (temp != NULL)
        {
            ump[temp->val]++;
            temp = temp->next;
        }
        ListNode *dH = new ListNode(-101);
        ListNode *temp2 = dH;
        temp = head;
        while (temp != NULL)
        {
            if (ump[temp->val] == 1)
            {
                ListNode *tempo = temp->next;
                temp->next = NULL;
                temp2->next = temp;
                temp2 = temp;
                temp = tempo;
            }
            else
            {
                temp = temp->next;
            }
        }
        return dH->next;
    }
};

// 1669. Merge In Between Linked Lists
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *temp = list2;
        ListNode *last = NULL;
        int i = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        last = temp;
        temp = list1;
        while (i != a)
        {
            temp = temp->next;
            i++;
        }
        ListNode *temp2 = temp->next;
        temp->next = list2;
        while (i != b)
        {
            temp2 = temp2->next;
            i++;
        }
        last->next = temp2->next;
        temp2->next = NULL;
        return list1;
    }
};
