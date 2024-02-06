//LeetCode

//21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ListNode* temp1;
        // ListNode* temp2;
        ListNode* c=new ListNode();
        ListNode* head=c;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                c->next=l1;
                l1=l1->next;
                c=c->next;
            }
            else{
                c->next=l2;
                l2=l2->next;
                c=c->next;
            }
        }
        if(l1!=NULL){
            c->next=l1;
        }
        else if(l2!=NULL){
            c->next=l2;
        }
        return head->next;
    }
};

//24. Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* l1=head;
        ListNode* l2=head->next;
        ListNode* c=new ListNode(0, head);
        head=c;
        while(l2!=NULL && l2->next!=NULL){
            c->next=l2;
            l1->next=l2->next;
            l2->next=l1;
            c=l1;
            l1=l1->next;
            l2=l1->next;
        }
        if(l2!=NULL){
            c->next=l2;
            l2->next=l1;
            l1->next=NULL;
        }
        return head->next;
    }
};