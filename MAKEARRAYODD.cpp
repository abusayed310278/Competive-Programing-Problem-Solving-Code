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

    int n, x;
    cin >> n >> x;

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        assert(a <= (1 << 30) && a >= 0);
        if (a & 1)
            odd++;
        else
            even++;
    }
    if (even == n && x % 2 == 0)
        cout << -1 << " ";
    else if (x & 1)
        cout << (even + 1) / 2 << " ";
    else
        cout << even << " ";
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