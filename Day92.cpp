// LeetCode

// 239. Sliding Window Maximum
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < k; i++)
        {
            int curr = nums[i];
            while (!dq.empty() && curr > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            int curr = nums[i];
            if (dq.front() == i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && curr > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

// 930. Binary Subarrays With Sum
class Solution
{
public:
    int forHelp(vector<int> &nums, int goal)
    {
        if (goal < 0)
        {
            return 0;
        }
        int count = 0;
        int currSum = 0;
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            currSum += nums[j];
            while (currSum > goal)
            {
                currSum -= nums[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return forHelp(nums, goal) - forHelp(nums, goal - 1);
    }
};