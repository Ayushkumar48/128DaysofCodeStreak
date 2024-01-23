//LeetCode


//442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                ans.push_back(abs(nums[i]));
            }
            nums[index] = -nums[index];
        }
        return ans;
    }
};

//540. Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int m=(s+e)>>1;
            if(m==0 || m==n-1){
                return nums[m];
            }
            else if(m%2==0){
                if(nums[m]==nums[m+1]){
                    s=m+1;
                }
                else if(nums[m]==nums[m-1]){
                    e=m-1;
                }
                else{
                    return nums[m];
                }
            }
            else{
                if(nums[m]==nums[m+1]){
                    e=m-1;
                }
                else if(nums[m]==nums[m-1]){
                    s=m+1;
                }
                else{
                    return nums[m];
                }
            }
        }
        return -1;
    }
};