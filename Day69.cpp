//LeetCode

//231. Power of Two
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 &&log2(n) == floor(log2(n)));
    }
};

//2351. First Letter to Appear Twice
class Solution {
public:
    char repeatedCharacter(string s) {
        bool a[26]={false};
        for(char &ch : s){
            if(a[ch-'a']==true){
                return ch;
            }
            else{
                a[ch-'a']=true;
            }
        }
        return ' ';
    }
};