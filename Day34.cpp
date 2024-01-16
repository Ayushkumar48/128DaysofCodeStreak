//LeetCode


//204. Count Primes
class Solution {
public:
    int countPrimes(int n) {
        int c = 0;
        if (n <= 2)
            return 0;
        int prime[n];
        for (int i = 2; i < n; i++) {
            prime[i] = 0;
        }
        for (int i = 2; i * i < n; i++) {
            if (prime[i] == 0) {
                for (int j = i * i; j < n; j = j + i) {
                    prime[j] = 1;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (prime[i] == 0)
                c++;
        }

        return c;
    }
};

//209. Minimum Size Subarray Sum
class Solution {
public:
    // int min(int a, int b){
    //     if(a>b){
    //         return b;
    //     }
    //     return a;
    // }
    int minSubArrayLen(int target, vector<int> &nums){
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = nums[0];
        int minIndex = INT_MAX;
        while (i < n && j < n){
            if(sum==target){
                minIndex=min(minIndex,j-i+1);
                j++;
                if(j>=n){
                    break;
                }
                sum=sum+nums[j]-nums[i];
                i++;
                if(i>=n){
                    break;
                }
            }
            else if(sum>target){
                minIndex=min(minIndex,j-i+1);
                sum-=nums[i];
                i++;
                if(i>=n){
                    break;
                }
            }
            else{
                j++;
                if(j>=n){
                    break;
                }
                sum+=nums[j];
            }
        }
        if(minIndex==INT_MAX){
            return 0;
        }
        return minIndex;
    }
};