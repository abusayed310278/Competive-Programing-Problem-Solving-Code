#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define lli long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const ll mod = 1e9 + 7;

ll power(ll n)
{

    ll res = 1, x = 2;
    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }

    return res;
}

void solve()
{
    // Write your solution code here
    ll n, x;
    cin >> n >> x;
    cout << (x * power(n - 1)) % mod << endl;
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