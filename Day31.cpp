//LeetCode


//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            mini=min(mini,prices[i-1]);
            profit=max(profit, prices[i]-mini);
        }
        return profit;
    }
};


//125. Valid Palindrome
class Solution {
public:
    int valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return 1;
        }
        return 0;
    }
    char toLowerCase(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return ch;
        }
        else{
            return ch-'A'+'a';
        }
    }

    bool isPalindrome(string s) {
        string x="";
        for(int i=0;i<s.size();i++){
            if(valid(s[i])){
                x.push_back(s[i]);
            }
        }
        for(int j=0;j<x.size();j++){
            x[j]=toLowerCase(x[j]);
        }
        int st=0;
        int ed=x.size()-1;
        while(st<=ed){
            if(x[st]!=x[ed]){
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
};