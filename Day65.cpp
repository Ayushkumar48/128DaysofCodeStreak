//LeetCode

//58. Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        while(i>=0){
            if(s[i]!=' '){
                break;
            }
            i--;
        }
        int count=0;
        while(i>=0){
            if(s[i]==' '){
                break;
            }
            count++;
            i--;
        }
        return count;
    }
};

//392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.size()){
            if(i<s.size() && j==t.size()){
                return false;
            }
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return true;
    }
};