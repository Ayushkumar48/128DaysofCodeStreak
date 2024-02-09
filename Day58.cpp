//LeetCode

// 203. Remove Linked List Elements
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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        ListNode* dH=new ListNode(0, head);
        ListNode* prev=dH;
        while(temp!=NULL){
            if(temp->val==val){
                temp=temp->next;
                prev->next=temp;
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        return dH->next;
    }
};

//234. Palindrome Linked List
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        //find middle node
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        // reverse
        ListNode* prev=NULL;
        ListNode* temp;
        while(slow!=NULL){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

        //checking
        ListNode* left=head;
        ListNode* right=prev;
        while(right!=NULL){
            if(right->val!=left->val){
                return false;
            }
            left=left->next;
            right=right->next;
        }
        return true;
    }
};