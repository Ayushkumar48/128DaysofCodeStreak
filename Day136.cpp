// LeetCode

// 300. Longest Increasing Subsequence
class Solution
{
public:
    int solveUsingBS(vector<int> &nums)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    // Solution with DP
    // int solveUsingTabulation(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
    //     for (int curr = n - 1; curr >= 0; curr--) {
    //         for (int prev = curr - 1; prev >= -1; prev--) {
    //             int include = 0;
    //             if (prev == -1 || nums[prev] < nums[curr]) {
    //                 include = 1 + dp[curr+1][curr+1];
    //             }
    //             int exclude = dp[curr+1][prev+1];
    //             dp[curr][prev + 1] = max(include, exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = solveUsingBS(nums);
        return ans;
    }
};

// 375. Guess Number Higher or Lower II
class Solution
{
public:
    int solve(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int start = n - 1; start >= 1; start--)
        {
            for (int end = 1; end <= n; end++)
            {
                if (start >= end)
                    continue;
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n)
    {
        int ans = solve(n);
        return ans;
    }
};