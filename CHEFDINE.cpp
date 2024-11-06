#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define int long long
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    unordered_set<int> st;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({b[i], a[i]});
    }

    sort(begin(v),end(v));

    int ans = 0;
    for (auto x : v)
    {
        int t = x.first;
        int c = x.second;
        if (st.find(c) != st.end())
            continue;
        st.insert(c);
        if (k == 0)
            break;
        k--;
        ans += t;
    }

    if (k)
        cout << -1 << endl;
    else
        cout << ans << endl;
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