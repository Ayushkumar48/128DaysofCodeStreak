// LeetCode

//41. First Missing Positive
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                nums[i]=n+1;
            }
        }
        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            int index=val-1;
            if(index<n && nums[index]>0){
                nums[index]*=-1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};

//42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int s=0;
        int e=n-1;
        int leftMax=height[s];
        int rightMax=height[e];
        int res=0;
        while(s<e){
            if(leftMax<rightMax){
                s+=1;
                leftMax=max(leftMax,height[s]);
                res+=leftMax-height[s];
            }
            else{
                e-=1;
                rightMax=max(rightMax,height[e]);
                res+=rightMax-height[e];
            }
        }
        return res;
    }
};