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

    int x, y;
    cin >> x >> y;

    if (x == y)
    {
        cout << 0 << endl;
        return;
    }
    if (y % x == 0)
        cout << (y / x) - 1 << endl;
    else
        cout << y / x << endl;
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