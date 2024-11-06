#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll n, a[N];

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {

        ll ans = 0;

        ll cnt1 = 0, cnt0 = 0;
        vector<ll> c;
        cin >> n;
        for (ll i = 1; i <= 2 * n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
                cnt1++; // odd
            else
            {
                cnt0++; // even
                c.push_back(__builtin_ctzll(a[i]));
            }
        }
        sort(c.begin(), c.end());
        if (cnt1 < cnt0)
        {
            for (ll i = 0; i < n - cnt1; i++)
                ans += c[i];
        }
        else if (cnt1 > cnt0)
        {
            ans = n - cnt0;
        }
        cout << ans << endl;
    }
    return 0;
}