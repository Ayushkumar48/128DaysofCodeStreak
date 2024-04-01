// LeetCode

// 70. Climbing Stairs
class Solution
{
public:
    int helper(int n, vector<int> &nums)
    {
        if (n == 0 || n == 1)
        {
            return nums[n];
        }
        if (nums[n] == -1)
        {
            int ans = helper(n - 1, nums) + helper(n - 2, nums);
            nums[n] = ans;
        }
        return nums[n];
    }
    int climbStairs(int n)
    {
        vector<int> nums(n + 1, -1);
        nums[0] = 1;
        nums[1] = 1;
        return helper(n, nums);
    }
};