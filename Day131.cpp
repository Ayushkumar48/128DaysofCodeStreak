// LeetCode

// 1545. Find Kth Bit in Nth Binary String
class Solution
{
public:
    string invert(string str)
    {
        for (char &c : str)
        {
            c ^= 1;
        }
        return str;
    }
    char findKthBit(int n, int k)
    {
        string str = "0";
        while (n > 0)
        {
            string reversed = str;
            for (char &c : reversed)
            {
                c ^= 1;
            }
            reverse(reversed.begin(), reversed.end());
            str.push_back('1');
            str += reversed;
            n--;
        }
        return str[k - 1];
    }
};

// 54. Spiral Matrix
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int totalElements = m * n;
        int startRow = 0;
        int endCol = n - 1;
        int endRow = m - 1;
        int startCol = 0;
        int count = 0;
        while (count < totalElements)
        {
            for (int i = startCol; i <= endCol && count < totalElements; i++)
            {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for (int i = startRow; i <= endRow && count < totalElements; i++)
            {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for (int i = endCol; i >= startCol && count < totalElements; i--)
            {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for (int i = endRow; i >= startRow && count < totalElements; i--)
            {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};

// 1991. Find the Middle Index in Array
class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int allSum = 0;
        for (auto it : nums)
        {
            allSum += it;
        }
        allSum -= nums[0];
        if (allSum == 0)
        {
            return 0;
        }
        int currSum = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            currSum += nums[i - 1];
            allSum -= nums[i];
            if (allSum == currSum)
            {
                return i;
            }
        }
        return -1;
    }
};

// 643. Maximum Average Subarray I
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double currSum = 0;
        double sum = 0;
        for (int i = 0; i < k; i++)
        {
            currSum += nums[i];
        }
        sum = currSum;
        int i = 0;
        int j = k;
        while (j < nums.size())
        {
            currSum = currSum - nums[i] + nums[j];
            sum = max(currSum, sum);
            i++;
            j++;
        }
        double currMax = sum / k;
        return currMax;
    }
};

// 532. K-diff Pairs in an Array
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;
        for (int it : nums)
        {
            ump[it]++;
        }
        int count = 0;
        if (k == 0)
        {
            for (auto it : ump)
            {
                if (it.second > 1)
                {
                    count++;
                }
            }
            return count;
        }
        for (auto it : ump)
        {
            int x = it.first - k;
            if (ump.find(x) != ump.end())
            {
                count++;
            }
        }
        return count;
    }
};

// 658. Find K Closest Elements
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &nums, int k, int x)
    {
        int s = 0;
        int e = nums.size() - 1;
        while (e - s >= k)
        {
            if (x - nums[s] > nums[e] - x)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        vector<int> ans;
        for (int i = s; i <= e; i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};