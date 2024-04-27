// LeetCode

// 912. Sort an Array
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        // Approach 1
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int it:nums){
        //     pq.push(it);
        // }
        // vector<int> ans(nums.size());
        // int i=0;
        // while(!pq.empty()){
        //     ans[i]=pq.top();
        //     i++;
        //     pq.pop();
        // }
        // return ans;

        // Approach 2
        map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }
        int i = 0;
        for (auto it : mp)
        {
            while (it.second != 0)
            {
                nums[i] = it.first;
                i++;
                it.second--;
            }
        }
        return nums;
    }
};

// 347. Top K Frequent Elements
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;
        for (auto it : nums)
        {
            ump[it]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : ump)
        {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while (k != 0)
        {
            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }
        return ans;
    }
};

// 322. Coin Change
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++)
        {
            int ans = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    int a = dp[i - coins[j]];
                    if (a != -1)
                    {
                        ans = min(ans, a + 1);
                    }
                }
            }
            if (ans != INT_MAX)
            {
                dp[i] = ans;
            }
        }
        return dp[amount];
    }
};