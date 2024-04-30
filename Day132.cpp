// LeetCode

// 55. Jump Game
class Solution
{
public:
    bool solve(vector<int> &nums, int index)
    {
        if (index == nums.size() - 1)
        {
            return true;
        }
        if (nums[index] == 0)
        {
            return false;
        }
        int num = nums[index];
        for (int i = 1; i < num + 1; i++)
        {
            int ans = solve(nums, index + i);
            if (ans == true)
            {
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }
        return solve(nums, 0);
    }
};