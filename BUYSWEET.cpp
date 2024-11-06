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
    int n, r;
    cin >> n >> r;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {a[i] - b[i], a[i]};
    }

    sort(begin(v) ,end(v));

    int ans=0;
    for (int i = 0; i < n; i++)
    {

        if (v[i].second > r)
            continue;
        // int sub = v[i].first - v[i].second;
        int sweetcnt = (r - (v[i].second - v[i].first)) / v[i].first;
        ans += sweetcnt;
        r -= (sweetcnt * v[i].first);
    }

    cout << ans << endl;
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