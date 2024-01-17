//LeetCode

//242. Valid Anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int> arr(26,0);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }
};

//268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int totalSum=0;
        for(int i=0; i<n; i++){
            totalSum+=nums[i];
        }
        return sum-totalSum;
    }
};