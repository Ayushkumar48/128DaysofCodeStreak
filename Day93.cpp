// LeetCode

// 122. Best Time to Buy and Sell Stock II
class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int sum = 0;
        int curr = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (curr < nums[i])
            {
                if (i + 1 >= nums.size())
                {
                    sum += (nums[i] - curr);
                    break;
                }
                else if (nums[i] > nums[i + 1])
                {
                    sum += (nums[i] - curr);
                    i++;
                    curr = nums[i];
                }
            }
            else
            {
                curr = nums[i];
            }
        }
        return sum;
    }
};