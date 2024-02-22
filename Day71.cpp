//LeetCode

// 205. Isomorphic Strings
class Solution {
public:
    bool atob(string s, string t){
        unordered_map<char, char> ump;
        int i=0;
        while(i<s.size()){
            if(ump.find(s[i])==ump.end()){
                ump.insert({s[i], t[i]});
            }
            else{
                if(ump[s[i]]!=t[i]){
                    return false;
                }
            }
            i++;
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        bool ans1=atob(s,t);
        bool ans2=atob(t,s);
        return ans1 && ans2;
    }
};

//724. Find Pivot Index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int allSum=0;
        for(auto it:nums){
            allSum+=it;
        }
        allSum -= nums[0];
        if(allSum == 0){
            return 0;
        }
        int currSum=0;
        for(int i=1; i<nums.size();i++){
            currSum+=nums[i-1];
            allSum-=nums[i];
            if(allSum==currSum){
                return i;
            }
        }
        return -1;
    }
};