#include <bits/stdc++.h>
#define endl "\n"
#define int long long
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
    int x, r, m;
    cin >> x >> r >> m;

    r *= 60;
    m *= 60;
    int time = min(x, r);
    if (r > x)
    {
        time += 2 * (r - x);
    }

    if (time <= m)
    {
        cout << "YES\n";
    }
    else
    {

        cout << "NO\n";
    }
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