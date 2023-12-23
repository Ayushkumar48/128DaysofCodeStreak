//Some LeetCode problems

//1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n=nums.size()-1;
      for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
      }
      return {-1,-1};
    }
};

//4. Median of two sorted arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i=0;
        int j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i++]);
            }
            else{
                merged.push_back(nums2[j++]);
            }
        }
        int x=merged.size()/2;
        if(merged.size()%2==0){
            int median1=merged[x-1];
            int median2=merged[x];
            return (static_cast<double>(median1) + static_cast<double>(median2))/2.0;
        }
        else{
            int median=merged[x];
            return static_cast<double>(median);
        }
    }
};

//9. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        int r;
        long n=0;
        int t=x;
        if(x<0){
            return false;
        }
        else if(x==0){
            return true;
        }
        else{
            while(x>0){
                r=x%10;
                n=r+n*10;
                x=x/10;
            }
            if(n==t){
                return true;
            }
        return false;
        }
    }
};