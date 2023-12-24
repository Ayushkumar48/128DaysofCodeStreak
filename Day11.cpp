// LeetCode
// 27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
               nums[index]=nums[i];
               index++;
            }
        }
        return index;
    }
};

// 34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        int start=search(nums,target,true);
        int end=search(nums,target,false);
        ans[0]=start;
        ans[1]=end;
        return ans;
    }
    int search(vector<int>& nums, int target,bool findFirstIndex){
        int ans=-1;
        int s=0;
        int e=nums.size()-1;
        int m;
        while(s<=e){
            m=s+(e-s)/2;
            if(target<nums[m])
            {
                e=m-1;
            }
            else if (target>nums[m])
            {
                s=m+1;
            }
            else
            {
                ans=m;
                if(findFirstIndex){
                    e=m-1;
                }
                else
                {
                    s=m+1;
                }
            }
        }
        return ans;
    }
};