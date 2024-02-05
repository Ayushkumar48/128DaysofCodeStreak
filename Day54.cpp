//LeetCode

//2. Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tail=nullptr;
        ListNode* head=nullptr;
        int carry=0;

        while((l1!=nullptr) || (l2!=nullptr) || (carry==1)){

            int addition = (l1!=nullptr?l1->val:0) + (l2!=nullptr?l2->val:0)+carry;

            if(addition>9){
                addition-=10;
                carry=1;
            }else{
                carry=0;
            }
            //addition contains the addition of two nodes
            //perform address transfer
            if(tail==nullptr){ //run only initially
                tail=new ListNode(addition,nullptr);
                head=tail; //set head to first element
            }else{
                tail->next=new ListNode(addition,nullptr);
                tail = tail->next;
            }

            //progress l1 and l2 
            if(l1!=nullptr)l1=l1->next;
            if(l2!=nullptr)l2=l2->next;


        }
        return head;
    }
};

//19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode* dummy=new ListNode(0, head);
        // ListNode* l=dummy;
        ListNode* r=head;
        int count=0;
        while(count<n){
            r=r->next;
            count++;
        }
        while(r!=NULL){
            dummy=dummy->next;
            r=r->next;
        }
        r=dummy->next;
        dummy->next=dummy->next->next;
        r->val=-1;
        if(head->val==-1){
            return dummy->next;
        }
        return head;
    }
};