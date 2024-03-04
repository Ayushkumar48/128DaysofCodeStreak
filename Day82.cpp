// LeetCode

// 2733. Neither Minimum nor Maximum
class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        if (nums.size() < 3)
            return -1;
        int min = INT_MAX;
        int max = INT_MIN;
        for (auto it : nums)
        {
            if (it < min)
            {
                min = it;
            }
            if (it > max)
            {
                max = it;
            }
        }
        for (auto it : nums)
        {
            if (it != min && it != max)
            {
                return it;
            }
        }
        return -1;
    }
};

// 961. N-Repeated Element in Size 2N Array
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        for (auto it : nums)
        {
            ump[it]++;
            if (ump[it] > 1)
            {
                return it;
            }
        }
        return -1;
    }
};