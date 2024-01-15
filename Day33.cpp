//LeetCode


// 169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                curr=nums[i];
            }
            else if(nums[i]==curr){
                count++;
            }
            else{
                count--;
            }
        }
        return curr;
    }
};

//189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};