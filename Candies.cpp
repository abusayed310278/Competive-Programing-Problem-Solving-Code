#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

void solve()
{

    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i - 1][j] += dp[i - 1][j - 1];
        }
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] > 0)
                dp[i][j] -= dp[i - 1][j - a[i] - 1];
            dp[i][j] = ((dp[i][j] % mod) + mod) % mod;
        }
    }

    cout << dp[n][k] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}