// LeetCode

// 1249. Minimum Remove to Make Valid Parentheses
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() && s[i] == ')')
            {
                s.erase(s.begin() + i);
                i--;
            }
            else if (s[i] == ')')
            {
                st.pop();
            }
            else if (s[i] == '(')
            {
                st.push(i);
            }
        }
        while (!st.empty())
        {
            s.erase(s.begin() + st.top());
            st.pop();
        }
        return s;
    }
};