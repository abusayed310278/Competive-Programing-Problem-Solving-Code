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

long long int ncr(int n, int r)
{

    long long int dp[n + 1][r + 1];
    for (int i = 0; i <= n; i++)
    {

        dp[i][0] = 1;
        for (int j = 1; j <= min(i, r); j++)
        {

            if (i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
        }
    }
    return dp[n][r];
}

void solve()
{

    int n, r;
    cin >> n >> r;
    cout << ncr(n, r) << endl;
}

int main()
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