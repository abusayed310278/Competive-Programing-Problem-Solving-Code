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
    int d, x, y;
    cin >> d >> x >> y;

    int denominator = d * x - 100;
    
    if (denominator == 0) {
        cout << 0 << endl;
        return;
    }

    int ans = 100 * (x - y) / denominator;

    if (ans < 0) {
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
