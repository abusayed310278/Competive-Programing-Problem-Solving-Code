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

const int mod = 998244353;

int modpow(int a, int n, int mod)
{

    a %= mod;
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (1LL * res * a) % mod;
        }

        a = (1LL * a * a) % mod;
        n >>= 1;
    }

    return res;
}

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n), pre(n), suf(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    suf[n - 1] = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        pre[i] = max(pre[i - 1], a[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = min(suf[i + 1], a[i + 1]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre[i] < a[i] and a[i] < suf[i])
        {
            cnt++;
        }
    }

    int ans = modpow(2, cnt, mod);
    if (cnt == n)
    {
        --ans;
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