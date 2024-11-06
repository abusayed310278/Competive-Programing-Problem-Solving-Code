#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define int long long int
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
    // Write your solution code here
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(begin(a) + 1, end(a));

    int minisum = 0;
    int mx = 0;
    for (int i = 1; i <= k; i++)
    {
        minisum += a[i];
        mx = max(mx, a[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == mx)
            cnt++; // maximum element from whole array
    }

    int x = 0;
    for (int i = 1; i <= k; i++)
    {
        if (a[i] == mx) // k smallest element
            x++;
    }

    vector<vector<int>> dp(cnt + 1, vector<int>(x + 1));

    for (int i = 0; i <= cnt; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else if (i != 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }

    cout << dp[cnt][x] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}