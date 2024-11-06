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

ll gcd(ll a, ll b)
{

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve()
{
    // Write your solution code here
    ll n, m;
    cin >> n >> m;
    ll tot = n * (n + 1) / 2;//1st natural number sum
    ll sum = tot + m;

    if (sum & 1)
    {
        cout << "No\n";
    }
    else
    {
        ll a = sum / 2;
        ll b = tot - a;

        cout << (gcd(a, b) == 1 ? "Yes" : "No") << endl;
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