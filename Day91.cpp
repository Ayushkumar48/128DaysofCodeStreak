// LeetCode

// 80. Remove Duplicates from Sorted Array II
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 1;
        }
        int curr = nums[0];
        bool flag = false;
        int i = 1;
        int j = 1;
        while (i < nums.size())
        {
            if (curr == nums[i])
            {
                if (flag == false)
                {
                    nums[j] = curr;
                    flag = true;
                    j++;
                }
            }
            else
            {
                curr = nums[i];
                flag = false;
                nums[j] = curr;
                j++;
            }
            i++;
        }
        return j;
    }
};

// 2485. Find the Pivot Integer
class Solution
{
public:
    int pivotInteger(int n)
    {
        int sum = (n * (n + 1)) / 2;
        int sum2 = 0;
        for (int i = 1; i < n + 1; i++)
        {
            sum2 += i;
            if (sum - sum2 == 0)
            {
                return i;
            }
            sum -= i;
        }
        return -1;
    }
};