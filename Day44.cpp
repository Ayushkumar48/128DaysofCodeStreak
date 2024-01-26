//LeetCode


//1913. Maximum Product Difference Between Two Pairs
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int s=INT_MAX;
        int ss=INT_MAX;
        int l=INT_MIN;
        int sl=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>l){
                sl=l;
                l=nums[i];
            }
            else{
                sl=max(nums[i],sl);
            }
            if(nums[i]<s){
                ss=s;
                s=nums[i];
            }
            else{
                ss=min(ss,nums[i]);
            }
        }
        int pd=l*sl-s*ss;
        return pd;
    }
};


//2149. Rearrange Array Elements by Sign
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int i=0;
        int j=1;
        for(auto it:nums){
            if(it>0){
                ans[i]=it;
                i+=2;
            }
            else{
                ans[j]=it;
                j+=2;
            }
        }
        return ans;
    }
};