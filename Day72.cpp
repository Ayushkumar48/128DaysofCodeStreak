//LeetCode

//160. Intersection of Two Linked Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=getLength(headA);
        int lenB=getLength(headB);
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        if(lenA<lenB){
            lenB-=lenA;
            while(lenB!=0){
                tempB=tempB->next;
                lenB--;
            }
        }
        else{
            lenA-=lenB;
            while(lenA!=0){
                tempA=tempA->next;
                lenA--;
            }
        }
        while(tempA!=NULL && tempB!=NULL){
            if(tempA==tempB){
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};

//164. Maximum Gap
//1st Approach
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            maxi=max(nums[i+1]-nums[i],maxi);
        }
        return maxi;
    }
};

//2nd Approach
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        map<int, int> ump;
        for(auto it:nums){
            ump[it]++;
        }
        nums.clear();
        for(auto it:ump){
            int count=it.second;
            while(count!=0){
                nums.push_back(it.first);
                count--;
            }
        }
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            maxi=max(nums[i+1]-nums[i],maxi);
        }
        return maxi;
    }
};