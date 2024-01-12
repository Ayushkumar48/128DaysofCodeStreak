//LeetCode

//78. Subsets
class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums, output, index+1, ans);
        int element=nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }
};

//81. Search in Rotated Sorted Array II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int m;
        while(s<=e){
            m=(s+e)>>1;
            if(nums[m]==target){
                return true;
            }
            if(nums[m]==nums[s] && nums[m]==nums[e]){
                s++;
                e--;
                continue;
            }
            if(nums[s]<=nums[m]){
                if(nums[s]<=target && target<=nums[m]){
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            else{
                if(nums[m]<=target && target<=nums[e]){
                    s=m+1;
                }
                else{
                    e=m-1;
                }
            }
        }
        return false;        
    }
};