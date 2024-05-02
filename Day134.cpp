// LeetCode

// 2441. Largest Positive Integer That Exists With Its Negative
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        priority_queue<int> positive;
        priority_queue<int, vector<int>, greater<int>> negative;
        for (auto it : nums)
        {
            if (it > 0)
            {
                positive.push(it);
            }
            else
            {
                negative.push(it);
            }
        }
        while (!positive.empty() && !negative.empty())
        {
            int mini = negative.top();
            int maxi = positive.top();
            if (abs(mini) < maxi)
            {
                positive.pop();
            }
            else if (abs(mini) > maxi)
            {
                negative.pop();
            }
            else
            {
                return maxi;
            }
        }
        return -1;
    }
};

// 1143. Longest Common Subsequence
class Solution
{
public:
    int longestCommonSubsequence(string a, string b)
    {
        vector<int> curr(a.size() + 1, 0);
        vector<int> next(a.size() + 1, 0);
        for (int j = b.size() - 1; j >= 0; j--)
        {
            for (int i = a.size() - 1; i >= 0; i--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + next[i + 1];
                }
                else
                {
                    ans = max(curr[i + 1], next[i]);
                }
                curr[i] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};

// 516. Longest Palindromic Subsequence
class Solution
{
public:
    int longestPalindromeSubseq(string a)
    {
        string b = a;
        reverse(b.begin(), b.end());
        vector<int> curr(a.size() + 1, 0);
        vector<int> next(a.size() + 1, 0);
        for (int j = b.size() - 1; j >= 0; j--)
        {
            for (int i = a.size() - 1; i >= 0; i--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + next[i + 1];
                }
                else
                {
                    ans = max(curr[i + 1], next[i]);
                }
                curr[i] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};