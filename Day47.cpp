//LeetCode


//167. Two Sum II - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int s=0;
        int e=arr.size()-1;
        while(s<e){
            if(arr[s]+arr[e]==target){
                return {s+1, e+1};
            }
            else if(arr[s]+arr[e]>target){
                e--;
            }
            else{
                s++;
            }
        }
        return {-1, -1};
    }
};

//169. Majority Element
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