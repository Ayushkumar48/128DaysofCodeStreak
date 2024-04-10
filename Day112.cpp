// LeetCode

// 198. House Robber
class Solution
{
public:
    int solve(vector<int> &nums, int index, int n, vector<int> &arr)
    {
        if (index >= n)
        {
            return 0;
        }
        if (arr[index] != -1)
        {
            return arr[index];
        }
        int a = nums[index] + solve(nums, index + 2, n, arr);
        int b = solve(nums, index + 1, n, arr);
        arr[index] = max(a, b);
        return arr[index];
    }
    int rob(vector<int> &nums)
    {
        vector<int> arr(nums.size(), -1);
        return solve(nums, 0, nums.size(), arr);
    }
};