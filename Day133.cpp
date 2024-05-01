// GFG

// 0 - 1 Knapsack Problem
class Solution
{
public:
    int solveUsingTabulation(int capacity, int wt[], int profit[], int n)
    {
        vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < capacity; i++)
        {
            dp[i][n] = 0;
        }
        for (int i = 0; i <= capacity; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int include = 0;
                if (wt[j] <= i)
                {
                    include += profit[j] + dp[i - wt[j]][j + 1];
                }
                int exclude = dp[i][j + 1];
                dp[i][j] = max(include, exclude);
            }
        }
        return dp[capacity][0];
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        return solveUsingTabulation(W, wt, val, n);
    }
};