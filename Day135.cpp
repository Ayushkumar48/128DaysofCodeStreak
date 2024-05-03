// LeetCode

// 165. Compare Version Numbers
class Solution
{
public:
    pair<string, int> getNum(string &str)
    {
        string s = "";
        bool flag = true;
        int dots = 0;
        for (auto it : str)
        {
            if (it == '.' && flag == true)
            {
                s.push_back('0');
            }
            if (it == '.')
            {
                flag = true;
                dots++;
                continue;
            }
            if (it == '0' && flag == true)
            {
                continue;
            }
            if (it >= '0' && it <= '9')
            {
                flag = false;
                s.push_back(it);
            }
        }
        if (flag == true)
        {
            s.push_back('0');
        }
        return {s, dots};
    }
    int equate(string &a, string &b, int dots1, int dots2)
    {
        if (dots1 != dots2)
        {
            int n = abs(dots1 - dots2);
            if (dots1 > dots2)
            {
                while (n != 0)
                {
                    b.push_back('0');
                    n--;
                }
            }
            else
            {
                while (n != 0)
                {
                    a.push_back('0');
                    n--;
                }
            }
        }
        if (a.size() > b.size())
            return 1;
        else if (a.size() < b.size())
            return -1;
        int i = 0;
        while (i < a.size())
        {
            if (a[i] > b[i])
                return 1;
            else if (a[i] < b[i])
                return -1;
            i++;
        }
        return 0;
    }
    int compareVersion(string a, string b)
    {
        pair<string, int> p1 = getNum(a);
        pair<string, int> p2 = getNum(b);
        string first = p1.first;
        string second = p2.first;
        int x = p1.second;
        int y = p2.second;
        return equate(first, second, x, y);
    }
};

// 72. Edit Distance
class Solution
{
public:
    int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= a.size())
        {
            return b.size() - j;
        }
        if (j >= b.size())
        {
            return a.size() - i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = solveUsingMem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
            int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
            int remove = 1 + solveUsingMem(a, b, i + 1, j, dp);
            ans = min(replace, min(insert, remove));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2)
    {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        int ans = solveUsingMem(word1, word2, i, j, dp);
        return ans;
    }
};