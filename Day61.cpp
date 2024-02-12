//LeetCode

//455. Assign Cookies
class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cookies) {
        sort(cookies.begin(), cookies.end());
        int children = 0;
        for(int i=0;i<child.size();i++){
            auto it = lower_bound(cookies.begin(), cookies.end(), child[i]);
            if(it!=cookies.end()){
                children++;
                cookies.erase(it);
            }
        }
        return children;
    }
};

//1929. Concatenation of Array
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()*2,-1);
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[i];
            ans[nums.size()+i]=nums[i];
        }
        return ans;
    }
};