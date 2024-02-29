// LeetCode

// 1304. Find N Unique Integers Sum up to Zero
class Solution {
public:
    vector<int> sumZero(int n) {
        if (n % 2 == 0) {
            vector<int> ans(n);
            for (int i = 0; i < n / 2; i++) {
                ans[i] = i + 1;
            }
            for (int i = n / 2; i < n; i++) {
                ans[i] = -1 * ans[i - (n / 2)];
            }
            return ans;
        }
        n--;
        vector<int> ans(n);
        for (int i = 0; i < n / 2; i++) {
            ans[i] = i + 1;
        }
        for (int i = n / 2; i < n; i++) {
            ans[i] = -1 * ans[i - (n / 2)];
        }
        ans.push_back(0);
        return ans;
    }
};

// 905. Sort Array By Parity
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]%2!=0){
                swap(nums[i], nums[j]);
                j--;
            }
            else{
                i++;
            }
        }
        return nums;
    }
};