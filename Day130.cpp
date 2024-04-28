// LeetCode

// 917. Reverse Only Letters
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        string letters = "";
        for (auto ch : s)
        {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                letters.push_back(ch);
            }
        }
        reverse(letters.begin(), letters.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                s[i] = letters[j];
                j++;
            }
        }
        return s;
    }
};

// 345. Reverse Vowels of a String
class Solution
{
public:
    string reverseVowels(string str)
    {
        unordered_set<char> uset = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int s = 0;
        int e = str.size() - 1;
        while (s <= e)
        {
            auto it1 = uset.find(str[s]);
            auto it2 = uset.find(str[e]);
            auto it3 = uset.end();
            if (it1 != it3 && it2 != it3)
            {
                swap(str[s], str[e]);
                s++;
                e--;
            }
            else if (it1 == it3 && it2 != it3)
            {
                s++;
            }
            else if (it1 != it3 && it2 == it3)
            {
                e--;
            }
            else
            {
                s++;
                e--;
            }
        }
        return str;
    }
};

// 443. String Compression
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        string s = "";
        chars.push_back(' ');
        char c = chars[0];
        int freq = 0;
        for (auto it : chars)
        {
            if (it == c)
            {
                freq++;
            }
            else
            {
                if (freq == 1)
                {
                    s.push_back(c);
                }
                else
                {
                    s.push_back(c);
                    string temp = to_string(freq);
                    for (auto it : temp)
                    {
                        s.push_back(it);
                    }
                }
                freq = 1;
                c = it;
            }
        }
        chars.clear();
        for (auto it : s)
        {
            chars.push_back(it);
        }
        return s.size();
    }
};