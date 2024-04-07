// LeetCode

// 678. Valid Parenthesis String
class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> st;
        stack<int> stars;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == '*')
            {
                stars.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    if (stars.empty())
                    {
                        return false;
                    }
                    stars.pop();
                }
            }
        }
        while (!st.empty() && !stars.empty())
        {
            if (st.top() > stars.top())
            {
                return false;
            }
            st.pop();
            stars.pop();
        }
        if (!st.empty())
        {
            return false;
        }
        return true;
    }
};