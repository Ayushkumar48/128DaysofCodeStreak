//LeetCode

//2529. Maximum Count of Positive Integer and Negative Integer
class Solution {
public:
    int negBinary(vector<int>& nums, int n){
        int s=0;
        int e=n-1;
        int m;
        while(s<=e){
            m=(s+e)>>1;
            if(nums[m]>=0){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return e;
    }
    int posBinary(vector<int>& nums, int n){
        int s=0;
        int e=n-1;
        int m;
        while(s<=e){
            m=(s+e)>>1;
            if(nums[m]<=0){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return s;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int neg=negBinary(nums, n)+1;
        int pos=n-posBinary(nums, n);
        return max(neg, pos);
    }
};


//1347. Minimum Number of Steps to Make Two Strings Anagram
class Solution {
public:
    int max(int a, int b){
        if(a>b){
            return a;
        }
        else{
            return b;
        }
    }
    int minSteps(string s, string t) {
        vector<int> a(26,0);
        // int a[26]={0};
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        int count=0;
        for(int j=0;j<26;j++){
            count +=max(0,a[j]);
        }
        //cdeeelot, acceiprt
        
        return count;
    }
};