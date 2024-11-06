#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 100000007

ll power(ll a, ll b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1)
            r = r * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return r;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll inv = (mod + 1) / 2;
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        ll ans1 = (power(3, n) - power(2, n + 1) + 1 + mod) % mod * inv % mod;
        ll ans2 = (power(4, n) - power(3, n + 1) + 3 * power(2, n) - 1 + 2 * mod) % mod * inv % mod;

        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
    
}