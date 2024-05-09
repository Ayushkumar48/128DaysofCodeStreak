// LeetCode

// 3075. Maximize Happiness of Selected Children
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        int countedChildren = 0;
        long long int sum = 0;
        sort(happiness.begin(), happiness.end());
        int i = happiness.size() - 1;
        while (k != countedChildren)
        {
            if (happiness[i] - countedChildren < 0)
            {
                return sum;
            }
            sum += (happiness[i] - countedChildren);
            i--;
            countedChildren++;
        }
        return sum;
    }
};