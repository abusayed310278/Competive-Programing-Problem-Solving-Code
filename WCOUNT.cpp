#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    int dp[501][501] = {0};
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < 501; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j < i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % m;
    }
    while (t--)
    {
        string s;
        cin >> s;
        int i = 0;
        unordered_map<char, int> mp;
        while (s[i] != '\0')
        {
            mp[s[i]]++;
            i++;
        }
        long ans = 1, len = s.length();
        for (auto it : mp)
        {
            ans = (ans * dp[len][it.second]) % m;
            len -= it.second;
        }
        cout << ans << endl;
    }
    return 0;
}