#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;
const int N = 400;

int a[N], pre[N], dp[N][N];

int sum(int l, int r)
{
    return pre[r] - (l == 0 ? 0 : pre[l - 1]);
}

int f(int l, int r)
{
    if (l == r)
        return 0;

    if (dp[l][r] != 0)
        return dp[l][r];

    int ans = 1e18;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, f(l, i) + f(i + 1, r)+sum(l,r));
    }
    

    return dp[l][r]=ans;
}

void solve()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i] = a[i];
        if (i)
            pre[i] += pre[i - 1];
    }
    memset(dp, 0, sizeof(dp));
    cout << f(0, n - 1) << endl;
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