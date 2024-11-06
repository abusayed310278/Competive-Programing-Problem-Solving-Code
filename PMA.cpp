#include <bits/stdc++.h>
#define endl "\n"
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

    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    ll mini = INT_MAX, maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2 == 0)
        {
            sum = sum + abs(a[i]);
            mini = min(mini, abs(a[i]));
        }
        else
        {
            sum = sum - abs(a[i]);
            maxi = max(maxi, abs(a[i]));
        }
    }

    cout << max(sum, sum + 2LL * (maxi - mini)) << "\n";
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