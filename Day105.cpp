// LeetCode

// 6. Zigzag Conversion
class Solution
{
public:
    vector<string> helper(string str, int n)
    {
        vector<string> v(n, "");
        int i = 0;
        while (i < str.size())
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= str.size())
                {
                    return v;
                }
                v[j] += str[i];
                i++;
            }
            for (int j = n - 2; j >= 1; j--)
            {
                if (i >= str.size())
                {
                    return v;
                }
                v[j] += str[i];
                i++;
            }
        }
        return v;
    }
    string convert(string str, int n)
    {
        vector<string> v = helper(str, n);
        str = "";
        for (int i = 0; i < n; i++)
        {
            str.append(v[i]);
        }
        return str;
    }
};