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
    int g, s, b;
    cin >> g >> s >> b;

    int ans = 0;
    if (g < 5)
    {
        ans += (5 - g);
    }
    if (s < 5)
    {
        ans += (5 - s);
    }
    if (b < 5)
    {
        ans += (5 - b);
    }

    cout << ans << endl;
}

int main()
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