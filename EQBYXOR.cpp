#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long int
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
    ll a, b, n;
    cin >> a >> b >> n;
    ll z = 1;
    ll x = (a ^ b);

    while (z < n)
        z *= 2;

    if (x == 0)
    {
        cout << 0 << endl;
    }
    else if (x < n)
    {
        cout << 1 << endl;
    }
    else if (x < z)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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