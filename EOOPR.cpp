#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
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
    int x, y;
    cin >> x >> y;

    if (x == y)
    {
        cout << 0 << endl;
        return;
    }

    if (x > y)
    {
        y -= x;
        if (y & 1)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    else if (x < y)
    {
        y -= x;
        if (y & 1)
            cout << 1 << endl;
        else if (!(y & 1) and (y / 2) & 1)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
}

int32_t main()
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