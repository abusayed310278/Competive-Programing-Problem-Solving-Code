#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

// https://www.hackerrank.com/challenges/game-of-stones-1/problem?isFullScreen=true

void solve()
{

    int n = 10;
    int dp[n];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int fn = 1;
        if (i - 2 >= 0)
            fn &= dp[i - 2];
        if (i - 3 >= 0)
            fn &= dp[i - 3];
        if (i - 5 >= 0)
            fn &= dp[i - 5];
        fn = !fn;
        dp[i] = fn;

        cout << i << "->" << dp[i] << endl;
    }
}

void solve1()
{

    int n;
    cin >> n;
    if (n % 7 <= 1)
    {
        cout << "Second" << endl;
    }
    else
    {
        cout << "First" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve1();
    }

    return 0;
}