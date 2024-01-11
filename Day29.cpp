//LeetCode

//69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        long s=0;
        long e=x;
        long m;
        while(s<=e){
            m=(s+e)>>1;
            if(m*m==x){
                return m;
            }
            else if(m*m<x){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return e;
    }
};

//75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int e=n-1;
        int m=0;
        while(m<=e){
            if(nums[m]==0){
                swap(nums[m],nums[s]);
                s++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[e]);
                e--;
            }
        }
    }
};