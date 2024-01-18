//LeetCode

//278. First Bad Version
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1;
        int e=n;
        int m;
        int ans;
        while(s<=e){
            m=s+(e-s)/2;
            if(isBadVersion(m)==false){
                s=m+1;
            }
            else{
                ans=m;
                e=m-1;
            }
        }
        return ans;
    }
};

//283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j!=-1){
            for(int i=j+1;i<n;i++){
                if(nums[i]!=0){
                    swap(nums[j],nums[i]);
                    j++;
                }
            }
        }
    }
};