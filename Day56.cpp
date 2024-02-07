//LeetCode

//61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int count = 1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        k=k%count;
        if(k==0){
            return head;
        }
        temp->next=head;
        for(int i=1;i<count-k;i++){
            head=head->next;
        }
        head=head->next;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};

//83. Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* temp=head;
        // ListNode* curr=head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummyHead= new ListNode(-110, head);
        ListNode* prev= dummyHead;
        while(head!=NULL && head->next!=NULL){
            // if(curr->val==curr->next->val && curr==head){
            //     ListNode* t=curr->next;
            //     curr->next=NULL;
            //     curr=t;
            // }
            // if(curr->next==NULL){
            //     break;
            // }
            if(head->val==(head->next->val)){
                prev->next=head->next;
                head->next=NULL;
                head=prev->next;
            }
            else{
                prev=head;
                head=head->next;
            }
        }
        return dummyHead->next;
    }
};