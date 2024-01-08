//LeetCode

//31. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }
        reverse(nums.begin()+index+1,nums.end());
    }
};



//33. Search in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int m;
        if(nums[s]<nums[e]){
            return s;
        }
        while(s<e){
            m=(s+e)>>1;
            if(nums[m]>=nums[0]){
                s=m+1;
            }
            else{
                e=m;
            }
        }
        return s;
    }
    int binarySearch(vector<int> &nums, int target, int s, int e){
        int m;
        while(s<=e){
            m=(s+e)>>1;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findMin(nums);
        if(nums[pivot]<=target && target<=nums[n-1]){
            return binarySearch(nums, target, pivot, n-1);
        }
        return binarySearch(nums, target, 0, pivot-1);
    }
};