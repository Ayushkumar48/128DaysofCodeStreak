// LeetCode

// 485. Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int c=0;
        int m=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                m=max(m,c);
                c=0;
            }
            else{
                c++;
            }
        }
        return m;
    }
};

// 414. Third Maximum Number
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> a(nums.begin(),nums.end());
        if(a.size()>2){
            int x=a.size()-3;
            auto it=a.end();
            it--;
            it--;
            it--;
            return *it;
        }
        return *--a.end();
    }
};