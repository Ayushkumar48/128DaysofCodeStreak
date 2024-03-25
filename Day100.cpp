// LeetCode

// 2248. Intersection of Multiple Arrays
class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        unordered_map<int, int> ump;
        for (auto it : nums)
        {
            for (auto i : it)
            {
                ump[i]++;
            }
        }
        int n = nums.size();
        vector<int> ans;
        for (auto it : ump)
        {
            if (it.second == n)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// 71. Simplify Path
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string s = "";
        path += '/';
        bool flag = false;
        for (auto ch : path)
        {
            if (ch == '/' && s == ".")
            {
                s = "";
                flag = true;
                continue;
            }
            if (ch == '/' && s == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
                s = "";
                flag = true;
                continue;
            }
            if (ch == '/' && !flag)
            {
                st.push(s);
                s = "";
                flag = true;
            }
            else if (ch == '/' && flag)
            {
                continue;
            }
            else
            {
                s += ch;
                flag = false;
            }
        }
        stack<string> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        s = "";
        if (st2.empty())
        {
            s += '/';
        }
        while (!st2.empty())
        {
            if (st2.top() == "")
            {
                st2.pop();
                continue;
            }
            s += '/';
            s.append(st2.top());
            st2.pop();
        }
        if (s == "")
        {
            s += '/';
        }
        return s;
    }
};