//LeetCode


//410. Split Array Largest Sum
class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int m){
        int currK=1;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            if(currSum+nums[i]<=m){
                currSum+=nums[i];
            }
            else{
                currK++;
                if(currK>k || nums[i]>m){
                    return false;
                }
                currSum=nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int max=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]>max){
                max=nums[i];
            }
        }
        int ans=-1;
        int s=max;
        int e=sum;
        int m;
        while(s<=e){
            m=(s+e)>>1;
            if(isPossible(nums, k, m)){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};

//441. Arranging Coins
#define ll long long
#include <cmath>
class Solution {
public:
    int arrangeCoins(int n) {
        ll ans=(-1+sqrt(1+8*(long)n))/2;
        return ans;
    }
};