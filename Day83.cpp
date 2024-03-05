// LeetCode

// 1750. Minimum Length of String After Deleting Similar Ends
class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (s[i] == s[j] && j - i > 0)
        {
            char curr = s[i];
            while (s[i] == curr && j - i >= 0)
            {
                i++;
            }
            while (s[j] == curr && j - i >= 0)
            {
                j--;
            }
        }
        if (j - i < 0)
        {
            return 0;
        }
        return j - i + 1;
    }
};

// 150. Evaluate Reverse Polish Notation
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto it : tokens)
        {
            if (it == "+")
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first + second);
            }
            else if (it == "-")
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first - second);
            }
            else if (it == "*")
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first * second);
            }
            else if (it == "/")
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first / second);
            }
            else
            {
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};