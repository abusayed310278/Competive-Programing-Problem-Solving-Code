#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
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
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int l = 1e9;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        v.push_back({r, l});
    }

    sort(begin(v), end(v));
    int ans = 0;
    int ma = -1;
    for (int i = 0; i < n; i++)
    {
        int l = v[i].second, r = v[i].first;
        if (l <= ma)
        {
            continue;
        }
        else
        {
            ans++;
            ma = r;
        }
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