// LeetCode

// 221. Maximal Square
class Solution
{
public:
    int solve(vector<vector<char>> &matrix, int i, int j, int row, int col, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= row || j >= col)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = solve(matrix, i, j + 1, row, col, maxi, dp);
        int diagonal = solve(matrix, i + 1, j + 1, row, col, maxi, dp);
        int down = solve(matrix, i + 1, j, row, col, maxi, dp);

        if (matrix[i][j] == '1')
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            dp[i][j] = ans;
            return ans;
        }
        else
        {
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int i = 0;
        int j = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        int ans = solve(matrix, i, j, row, col, maxi, dp);
        return maxi * maxi;
    }
};