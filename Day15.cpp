// LeetCode

// 1137. N-th Tribonacci Number
class Solution {
public:
    int tribonacci(int n) {
        if(n<=0)
            return n;
        else if(n==1 || n==2)
            return 1;
        int d;
        int a,b,c;
        a=0;b=1;c=1;
        for(int i=3;i<=n;i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;

    }
};

// 1295. Find Numbers with Even Number of Digits
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even=0;
        for(int num: nums){
            int x=floor(log10(num))+1;
            if(x%2==0){
                even++;
            }
        }
        return even;
    }
};