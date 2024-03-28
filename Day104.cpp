// LeetCode

// 2958. Length of Longest Subarray With at Most K Frequency
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
        {
            return 1;
        }
        unordered_map<int, int> ump;
        int i = 0;
        int j = 0;
        int maxi = 0;
        while (i <= j && j < nums.size())
        {
            if (ump.find(nums[j]) != ump.end())
            {
                if (ump[nums[j]] == k)
                {
                    maxi = max(maxi, j - i);
                    while (nums[i] != nums[j])
                    {
                        ump[nums[i]]--;
                        i++;
                    }
                    i++;
                    j++;
                }
                else
                {
                    ump[nums[j]]++;
                    j++;
                }
            }
            else
            {
                ump[nums[j]] = 1;
                j++;
            }
        }
        maxi = max(maxi, j - i);
        return maxi;
    }
};