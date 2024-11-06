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

    
    int D, d, p, q;
    cin >> D >> d >> p >> q;

    int a = p;
    int diff = q;
    int n = D / d;
    int rem = D % d;

    int ans = d * ((n* (2 * a + (n - 1) * diff))/2) + rem * (a + n * diff);

    cout << ans << endl;
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