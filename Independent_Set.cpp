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
const int N = 1e5 + 1;
vi g[N];

int dp[N][2];
int f(int u, int paint, int par)
{
    int ans=1;
    // int &ans = dp[u][paint];
    if(dp[u][paint]!=-1)return dp[u][paint];
    for (auto child : g[u])
    {
        if (child != par)
        {
            if (paint)
            {
                ans *= f(child, 0, u) + f(child, 1, u);
            }
            else
            {
                ans *= f(child, 1, u);
            }
            ans %= mod;
        }
    }

    return dp[u][paint]=ans;
}

void solve()
{

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));
    cout << (f(1, 0, 0) + f(1, 1, 0)) % mod << endl;
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