// LeetCode

// 50. Pow(x, n)
class Solution
{
public:
    double power(double x, long long n)
    {
        if (x == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        double ans;
        if (n % 2 == 0)
        {
            ans = myPow(x, n / 2);
            ans = ans * ans;
        }
        else
        {
            ans = x * myPow(x, n - 1);
        }
        return ans;
    }
    double myPow(double x, int n)
    {
        double ans;
        if (n > 0)
        {
            ans = power(x, n);
            return ans;
        }
        else
        {
            long b = n;
            ans = power(x, -1 * b);
            ans = 1 / ans;
            return ans;
        }
    }
};

// 326. Power of Three
#include <cmath>
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // Approach 1
        if (n <= 0)
        {
            return false;
        }
        double ans = log10(n) / log10(3);
        return ans == (int)ans;

        // Approach 2
        if (n <= 0)
        {
            return false;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};

// 342. Power of Four
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        double ans = log10(n) / log10(4);
        return ans == (int)ans;
    }
};