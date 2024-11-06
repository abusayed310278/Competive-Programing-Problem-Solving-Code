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

void solve()
{
    // Write your solution code here
    int n, x;
    cin >> n >> x;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mini = min(a, mini);
    }

    int ts = 0;
    if (x % mini == 0)
    {
        ts = x / mini;
    }
    else
    {
        ts = (x / mini) + 1;
    }

    int ans = n;
    ans = max(ans, ts);

    cout << ans << endl;
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