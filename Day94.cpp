// LeetCode

// 151. Reverse Words in a String
class Solution
{
public:
    string reverseWords(string s)
    {
        bool flag = false;
        s += ' ';
        stack<string> st;
        string str = "";
        for (auto ch : s)
        {
            if (ch == ' ')
            {
                if (flag == true)
                {
                    flag = false;
                    st.push(str);
                    str.clear();
                }
            }
            else
            {
                str += ch;
                if (flag == false)
                {
                    flag = true;
                }
            }
        }
        str.clear();
        while (!st.empty())
        {
            str.append(st.top());
            str += ' ';
            st.pop();
        }
        str.erase(str.begin() + str.size() - 1);
        return str;
    }
};

// 1190. Reverse Substrings Between Each Pair of Parentheses
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (st.empty())
                {
                    // reverse(s.begin()+st.top()+1, s.begin()+i);
                    break;
                }
                reverse(s.begin() + st.top() + 1, s.begin() + i);
                st.pop();
            }
            else if (s[i] == '(')
            {
                st.push(i);
            }
        }
        string str;
        for (char ch : s)
        {
            if (ch != '(' && ch != ')')
            {
                str += ch;
            }
        }
        return str;
    }
};