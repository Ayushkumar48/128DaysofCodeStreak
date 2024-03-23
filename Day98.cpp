// LeetCode

// 225. Implement Stack using Queues
class MyStack
{
public:
    queue<int> firstQueue;
    queue<int> secondQueue;
    MyStack()
    {
    }

    void push(int x)
    {
        if (firstQueue.empty())
        {
            firstQueue.push(x);
        }
        else
        {
            while (!firstQueue.empty())
            {
                secondQueue.push(firstQueue.front());
                firstQueue.pop();
            }
            firstQueue.push(x);
            while (!secondQueue.empty())
            {
                firstQueue.push(secondQueue.front());
                secondQueue.pop();
            }
        }
    }

    int pop()
    {
        int topElement = firstQueue.front();
        firstQueue.pop();
        return topElement;
    }

    int top()
    {
        return firstQueue.front();
    }

    bool empty()
    {
        return firstQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// 232. Implement Queue using Stacks
class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (st1.empty())
        {
            st1.push(x);
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(x);
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

    int pop()
    {
        int a = st1.top();
        st1.pop();
        return a;
    }

    int peek()
    {
        return st1.top();
    }

    bool empty()
    {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// 234. Palindrome Linked List
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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
        {
            return true;
        }
        stack<int> st;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == NULL)
        {
            while (slow != NULL)
            {
                if (slow->val != st.top())
                {
                    return false;
                }
                st.pop();
                slow = slow->next;
            }
        }
        else
        {
            slow = slow->next;
            while (slow != NULL)
            {
                if (slow->val != st.top())
                {
                    return false;
                }
                st.pop();
                slow = slow->next;
            }
        }
        return true;
    }
};
