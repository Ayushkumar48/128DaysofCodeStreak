//LeetCode

//556. Next Greater Element III
class Solution {
public:
    void nextPermutation(vector<int> &nums){
        int ind=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
    int nextGreaterElement(int n) {
        if (n == INT_MAX || n < 10) {
            return -1;
        }
        vector<int> v;
        int x = n;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        int s=v.size();
        reverse(v.begin(),v.end());
        nextPermutation(v);
        long b = 0;
        for (int i = 0; i < s; i++) {
            b = b * 10 + v[i];
        }
        if (b > n && b <= INT_MAX) {
            return b;
        }
        return -1;
    }
};

//645. Set Mismatch
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int dup;
        for(int i=1;i<=n;i++){
            if(nums[abs(nums[i-1])-1]<0){
                dup=abs(nums[i-1]);
            }
            else{
                nums[abs(nums[i-1])-1]*=-1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return {dup,i+1};
            }
        }
        return {-1,-1};
    }
};