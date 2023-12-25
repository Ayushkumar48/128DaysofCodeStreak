// LeetCode
// 35. Search Insert Position
class Solution {
public:
    
    int searchInsert(vector<int>& nums, int target) {
        int s=0;int e=nums.size()-1;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target){
                return m;
            }
            else if(target>nums[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
            if((s==m)&&(target<nums[m])){
                return m;
            }
            else if((e==m)&&(target>nums[m])){
                return m+1;
            }
        }
        return -1;
    }
};

// 509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        if(n<=0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        int a=0;
        int b=1;
        int c;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};