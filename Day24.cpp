//LeetCode

// 7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long b=0;
        while(x!=0){
            b=b*10+x%10;
            x=x/10;
        }
        if(b>INT_MAX || b<INT_MIN){
            return 0;
        }
        return int(b);
    }
};

// 204. Count Primes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> p(n,true);
        if(p.size()<3){
            return 0;
        }
        int c=1;
        p[0]=false;
        p[1]=false;
        for (long i = 3; i < n; i+=2)
        {
            if(p[i]){
                c++;
                for (long j = i*i; j < n; j+=i)
                {
                    p[j]=false;
                }
            
            }
        }
        return c;
    }
};