// LeetCode

// 28. Find the Index of the First Occurrence in a String
class Solution
{
public:
    int checking(string &haystack, string &needle, int s)
    {
        int i = s;
        int j = 0;
        while (j < needle.size())
        {
            if (needle[j] != haystack[i])
            {
                return i + 1;
            }
            i++;
            j++;
        }
        return -1;
    }
    int strStr(string haystack, string needle)
    {
        int i = 0;
        while (i < haystack.size())
        {
            if (needle[0] == haystack[i])
            {
                int index = checking(haystack, needle, i);
                if (index == -1)
                {
                    return i;
                }
                i++;
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
};

// 1299. Replace Elements with Greatest Element on Right Side
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        int max = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int curr = arr[i];
            arr[i] = max;
            if (curr > max)
            {
                max = curr;
            }
        }
        arr[n - 1] = -1;
        return arr;
    }
};