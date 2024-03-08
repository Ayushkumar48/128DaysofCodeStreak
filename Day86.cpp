// LeetCode

// 3005. Count Elements With Maximum Frequency
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (auto it : nums)
        {
            umap[it]++;
        }
        int maxi = 0;
        for (auto it : umap)
        {
            maxi = max(maxi, it.second);
        }
        int count = 0;
        for (auto it : umap)
        {
            if (maxi == it.second)
            {
                count++;
            }
        }
        return count * maxi;
    }
};

// 2108. Find First Palindromic String in the Array
class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto it : words)
        {
            string s = it;
            reverse(s.begin(), s.end());
            if (s == it)
            {
                return it;
            }
        }
        return "";
    }
};