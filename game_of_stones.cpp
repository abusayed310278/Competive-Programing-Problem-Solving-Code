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

const int N = 105;
int dp[N];
void pre()
{

    memset(dp,0,sizeof(dp));
    for (int i = 0; i < N ; i++)
    {
        if (i % 7 == 0 or i % 7 == 1)
            dp[i] = 0;
        else
            dp[i] = 1;
    }
}

void solve()
{
    pre();
    int n;
    cin >> n;
    if (dp[n])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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