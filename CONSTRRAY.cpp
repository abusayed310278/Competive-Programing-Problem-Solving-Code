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
    ll n;
    cin >> n;
    if (n & 1)
    {
        cout << "-1" << endl;
        return;
    }

    if (n == 4)
    {
        cout << "0 -5 343 -100" << endl;
    }
    else
    {

        cout << "1";

        ll b = -2;
        for (ll i = 2; i < n; i++)
        {
            cout << " " << b;
            b *= -1;
        }

        cout << " -1" << endl;
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