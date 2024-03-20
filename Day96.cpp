// LeetCode

// 49. Group Anagrams
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        if (strs.size() == 1)
        {
            ans.push_back(strs);
            return ans;
        }
        unordered_map<string, int> ump;
        for (string str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            auto it = ump.find(temp);
            if (it == ump.end())
            {
                vector<string> tempo;
                tempo.push_back(str);
                ans.push_back(tempo);
                ump[temp] = ans.size() - 1;
            }
            else
            {
                ans[it->second].push_back(str);
            }
        }
        return ans;
    }
};

// 202. Happy Number
class Solution
{
public:
    int processed(int num)
    {
        int powered = 0;
        while (num > 0)
        {
            int temp = num % 10;
            powered += (temp * temp);
            num /= 10;
        }
        return powered;
    }
    bool isHappy(int n)
    {
        unordered_set<int> uset;
        uset.insert(n);
        while (n != 1)
        {
            int temp = processed(n);
            if (uset.find(temp) != uset.end())
            {
                return false;
            }
            uset.insert(temp);
            n = temp;
        }
        return true;
    }
};