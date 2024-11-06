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
    int n;
    cin >> n;
    vector<int> a(n);
    int tot = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }

    sort(begin(a), end(a), greater<int>());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (ll)(sum) * (1000 * (n - i) - (tot - sum)));
        sum += a[i];
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