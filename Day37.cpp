//LeetCode

//287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0){
                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1]*=-1;
            }
        }
        return nums[n-1];
    }
};

//344. Reverse String
class Solution {
public:
    void reverseString(vector<char>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            swap(nums[s],nums[e]);
            s++;e--;
        }
    }
};