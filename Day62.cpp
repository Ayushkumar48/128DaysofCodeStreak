//LeetCode

//1920. Build Array from Permutation
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};

//2769. Find the Maximum Achievable Number
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num+2*t;
    }
};