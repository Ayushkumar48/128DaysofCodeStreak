// LeetCode

// 138. Copy List with Random Pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        unordered_map<Node *, Node *> ump;
        Node *temp = head;
        Node *newHead = new Node(temp->val);
        Node *newTemp = newHead;
        ump[temp] = newTemp;
        temp = temp->next;
        while (temp != NULL)
        {
            Node *tempo = new Node(temp->val);
            newTemp->next = tempo;
            newTemp = tempo;
            ump[temp] = newTemp;
            temp = temp->next;
        }
        temp = head;
        newTemp = newHead;
        while (temp != NULL)
        {
            Node *it = ump[temp->random];
            newTemp->random = it;
            newTemp = newTemp->next;
            temp = temp->next;
        }
        return newHead;
    }
};

// 88. Merge Sorted Array
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            int i = 0;
            int j = 0;
            while (j < n)
            {
                nums1[i] = nums2[j];
                i++;
                j++;
            }
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int k = nums1.size() - 1;
        while (i >= -1 && j >= 0)
        {
            if (i == -1)
            {
                while (j >= 0)
                {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
                return;
            }
            if (nums2[j] >= nums1[i])
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            else
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
    }
};