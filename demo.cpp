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
const int N = 3001;
int n, a[N], sum = 0;
int dp[N][N][2];

int f(int i, int j, int turn)
{

    if (i > j)
        return 0;

    //int &ans = dp[i][j][turn];
    if (dp[i][j][turn] != 1e18)return dp[i][j][turn];
        

    int ans=0;
    if (turn == 0)
    {
        ans = max(a[i] + f(i + 1, j, 1 - turn),
                  a[j] + f(i, j - 1, 1 - turn));
    }
    else
    {
        ans = min(f(i + 1, j, 1 - turn),
                  f(i, j - 1, 1 - turn));
    }

    return dp[i][j][turn]=ans;


}

void solve()
{
    memset(dp, 1e18, sizeof(dp));
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j][0] = dp[i][j][1] = 1e18;
        }
    }



    int sumx = f(0, n - 1, 0);
    int sumy = sum - sumx;

    cout << sumx - sumy << endl;
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