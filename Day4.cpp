#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int main()
{
    string str = "dsdjsbdjcjnsd";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    cout << str << endl;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    cout << str << endl;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << endl;
    string str = "125643";
    sort(str.begin(), str.end(), greater<int>());
    cout << str;

    string str = "sapejjednoqfkjjjwlklj";
    int freq[26];

    for (int i = 0; i < 26; i++)
    {
        /* code */
    }

    cout << getBit(5, 2) << endl;
    return 0;
}
