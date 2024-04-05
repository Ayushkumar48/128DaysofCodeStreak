// LeetCode

// 1544. Make The String Great
class Solution
{
public:
    string makeGood(string s)
    {
        string result;
        for (char c : s)
        {
            if (!result.empty() && abs(c - result.back()) == 32)
            {
                result.pop_back();
            }
            else
            {
                result.push_back(c);
            }
        }
        return result;
    }
};
