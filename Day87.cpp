// LeetCode

// 921. Minimum Add to Make Parentheses Valid
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int count = 0;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                st.push('(');
            }
            else
            {
                if (st.empty())
                {
                    count++;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return count + st.size();
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