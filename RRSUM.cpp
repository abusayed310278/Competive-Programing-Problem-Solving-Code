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
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int k;
        cin >> k;
        if ((k < (n + 2ll)) || (k > (3ll * n)))
            cout << "0\n";
        else
            cout << n - abs(((2ll * n) + 1ll) - k) << "\n";
    }
}

int32_t main()
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