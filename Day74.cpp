//LeetCode

//2678. Number of Senior Citizens
#include <bits/stdc++.h>
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            int num=(details[i][11]-'0')*10+(details[i][12]-'0');
            if(num>60){
                count++;
            }
        }
        return count;
    }
};

//2951. Find the Peaks
class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> ans;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};