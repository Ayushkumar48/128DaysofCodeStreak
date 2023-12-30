// LeetCode
// 2540. Minimum Common Value

class Solution {
public:
    bool binarySearch(vector<int>& nums2, int target){
        int s=0;
        int e=nums2.size()-1;
        int m;
        while(s<=e){
            m=s+(e-s)/2;
            if(nums2[m]==target){
                return true;
            }
            if(nums2[m]>target){
                e=m-1;
            }
            else {
                s=m+1;
            }
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            if(binarySearch(nums2, nums1[i])){
                return nums1[i];
            }
        }
        return -1;
    }
};