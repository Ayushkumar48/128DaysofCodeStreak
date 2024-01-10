//LeetCode

//53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};



//69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        long s=0;
        long e=x;
        long m;
        while(s<=e){
            m=(s+e)>>1;
            if(m*m==x){
                return m;
            }
            else if(m*m<x){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return e;
    }
};