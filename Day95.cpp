// LeetCode

// 383. Ransom Note
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> ump;
        for (auto ch : ransomNote)
        {
            ump[ch]++;
        }
        for (auto ch : magazine)
        {
            ump[ch]--;
        }
        for (auto it : ump)
        {
            if (it.second > 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 219. Contains Duplicate II
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = ump.find(nums[i]);
            if (it == ump.end())
            {
                ump[nums[i]] = i;
            }
            else
            {
                if (abs(ump[nums[i]] - i) <= k)
                {
                    return true;
                }
                else
                {
                    ump[nums[i]] = i;
                }
            }
        }
        return false;
    }
};