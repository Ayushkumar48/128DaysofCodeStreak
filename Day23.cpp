// LeetCode

// 217. Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])){
                return true;
            }
            else{
                s.insert(nums[i]);
            }
        }
        return false;
    }
};

// 7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long b=0;
        while(x!=0){
            b=b*10+x%10;
            x=x/10;
        }
        if(b>INT_MAX || b<INT_MIN){
            return 0;
        }
        return int(b);
    }
};