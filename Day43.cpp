//LeetCode

//1752. Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag++;
            }
        }
        if(nums[n-1]>nums[0]){
            flag++;
        }
        if(flag<=1){
            return true;
        }
        return false;
    }
};


//1910. Remove All Occurrences of a Substring
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.size()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};