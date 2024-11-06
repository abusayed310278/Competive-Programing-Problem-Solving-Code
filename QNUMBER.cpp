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
    ll n, tot = 1, N;
    int q;
    cin >> n >> q;

    N = n;

    vector<ll> prime;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            prime.push_back(i);
            int cnt = 0;
            while (N % i == 0)
            {
                N /= i; // Fix division here
                cnt++;
            }
            tot *= (cnt + 1);
        }
    }

    if (N > 1)
    {
        tot *= 2;
        prime.push_back(N);
    }

    while (q--)
    {
        ll t, k;
        cin >> t >> k;
        ll res;

        if (t == 1)
        {
            ll g = __gcd(k, n);
            res = 1;
            for (const auto &p : prime)
            {
                int cnt = 0;
                while (g % p == 0)
                {
                    g /= p;
                    cnt++;
                }
                res *= (cnt + 1);
            }
            cout << res << endl;
        }
        else
        {
            res = 0;
            if (n % k == 0)
            {
                ll g = n / k;
                res = 1;
                for (const auto &p : prime)
                {
                    int cnt = 0;
                    while (g % p == 0)
                    {
                        g /= p; // Fix division here
                        cnt++;
                    }
                    res *= (cnt + 1);
                }
            }

            if (t == 3)
                res = tot - res;

            cout << res << endl;
        }
    }
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
