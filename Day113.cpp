// LeetCode

// 46. Permutations
class Solution
{
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int i)
    {
        if (i >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            helper(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() == 1)
        {
            ans.push_back(nums);
            return ans;
        }
        helper(nums, ans, 0);
        return ans;
    }
};

// 213. House Robber II
class Solution
{
public:
    int solve(vector<int> &nums, int s, int e, vector<int> &arr)
    {
        if (s > e)
        {
            return 0;
        }
        if (arr[s] != -1)
        {
            return arr[s];
        }
        int a = nums[s] + solve(nums, s + 2, e, arr);
        int b = solve(nums, s + 1, e, arr);
        arr[s] = max(a, b);
        return arr[s];
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> arr(nums.size(), -1);
        int a = solve(nums, 0, nums.size() - 2, arr);
        arr.assign(nums.size(), -1);
        int b = solve(nums, 1, nums.size() - 1, arr);
        return max(a, b);
    }
};