//LeetCode

//387. First Unique Character in a String
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> st(26,0);
        for(auto ch:s){
            st[ch-'a']++;
        }
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(st[ch-'a']==1){
                return i;
            }
        }
        return -1;xxxx
    }
};

//2206. Divide Array Into Equal Pairs
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto it:nums){
            if(mp.find(it)!=mp.end()){
                if(mp[it]==true){
                    mp[it]=false;
                }
                else{
                    mp[it]=true;
                }
            }
            else{
                mp.insert({it,false});
            }
        }
        for(auto it:mp){
            if(mp[it.first]==false){
                return false;
            }
        }
        return true;
    }
};