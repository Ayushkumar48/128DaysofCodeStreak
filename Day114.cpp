// Some more interesting questions on recusrion. Later will solve them using Dynamic Programming

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dearrangements(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    int ans = (n - 1) * (dearrangements(n - 1) + dearrangements(n - 2));
    return ans;
}

int getPaintWays(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k + (k * (k - 1));
    int ans = (k - 1) * (getPaintWays(n - 2, k) + getPaintWays(n - 1, k));
    return ans;
}

int minDistance(string &word1, string &word2, int i, int j)
{
    if (i >= word1.size())
    {
        return word2.size() - j;
    }
    if (j >= word2.size())
    {
        return word1.size() - i;
    }
    int ans = 0;
    if (word1[i] == word2[j])
    {
        ans = minDistance(word1, word2, i + 1, j + 1);
    }
    else
    {
        int a = 1 + minDistance(word1, word2, i, j + 1);
        int b = 1 + minDistance(word1, word2, i + 1, j);
        int c = 1 + minDistance(word1, word2, i + 1, j + 1);
        ans = min(a, min(b, c));
    }
    return ans;
}

int main()
{
    int ans1 = dearrangements(4);
    cout << ans1;
    int ans2 = getPaintWays(3, 3);
    cout << ans2;
    string str1 = "LOLLOL";
    string str2 = "WIWIWIW";
    int ans3 = minDistance(str1, str2, 0, 0);
    cout << ans3;
    return 0;
}
