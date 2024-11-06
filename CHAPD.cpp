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
    ll a, b;
    cin >> a >> b;

    while (1)
    {

        ll g = gcd(a, b);
        if (g == 1)
            break;
        b /= g;
    }

    if (b == 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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