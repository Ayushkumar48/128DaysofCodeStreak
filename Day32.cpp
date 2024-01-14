//LeetCode

//136. Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr=0;
	    for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
	    return xorr;
    }
};

//153. Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int m;
        if(nums[s]<nums[e]){
            return nums[s];
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
        return nums[s];
    }
};