// LeetCode

// 1672. Richest Customer Wealth
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int w=0;
        for(int i=0;i<accounts.size();i++){
            int c=0;
            for(int j=0;j<accounts[i].size();j++){
                c+=accounts[i][j];
            }
            w=max(c,w);
        }
        return w;
    }
};

// 1768. Merge Strings Alternately
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string res="";
    
        while (i<word1.size() && j<word2.size()){
            res+=word1[i++];
            res+=word2[j++];
        }
        while (i<word1.size()){
            res+=word1[i++];
        }
          while (j<word2.size()){
            res+=word2[j++];
        }
        return res;
    }
};
