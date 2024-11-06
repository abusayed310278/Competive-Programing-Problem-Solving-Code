#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;
const ll maxn = 1e5 + 25;
ll a[maxn];
ll n, h;

bool valid(ll k)
{

    ll time = 0;
    for (int i = 0; i < n; i++)
    {
        time += (a[i] + k - 1) / k; // same as ceil((float)(a[i]/k); it gives precision error so i used  time += (a[i] + k - 1) / k;
    }

    return time <= h;
}

void solve()
{
    // Write your solution code here
    cin >> n >> h;
    ll ma = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        ma = max(a[i], ma);
    }

    ll l = 1, r = ma;
    ll ans = r;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (valid(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

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