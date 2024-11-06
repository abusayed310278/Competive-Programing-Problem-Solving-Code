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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<int> cnt(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= m;
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] %= m;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += cnt[(m - b[i]) % m];
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