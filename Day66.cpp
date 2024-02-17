//LeetCode

//14. Longest Common Prefix
class Solution {
public:
    string update(string curr, string str){
        string newStr="";
        int i=0;
        while(i<curr.size() && i<str.size()){
            if(curr[i] != str[i]){
                return newStr;
            }
            newStr+=curr[i];
            i++;
        }
        return newStr;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string currPrefix=strs[0];
        int i=1;
        while(i<strs.size()){
            currPrefix=update(currPrefix, strs[i]);
            i++;
        }
        return currPrefix;
    }
};

//1481. Least Number of Unique Integers after K Removals
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        arr.clear();
        for(auto it:mp){
            arr.push_back(it.second);
        }
        sort(arr.begin(),arr.end(), greater<int>());
        for(int i=arr.size()-1;i>=0;i--){
            if(k==0){
                return arr.size();
            }
            k-=arr[i];
            if(k==0){
                arr.pop_back();
                return arr.size();
            }
            else if(k>0){
                arr.pop_back();
            }
            else{
                return arr.size();
            }
        }
        return arr.size();
    }
};