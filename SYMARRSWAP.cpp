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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            swap(a[i], b[i]);
        }
    }

    multiset<int> st;
    for (auto x : a)
    {
        st.emplace(x);
    }

    // for (auto x : st)
    //     cout << x << " ";

    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++)
    {
        c.push_back({a[i], b[i]});
    }

    sort(begin(c), end(c));
    // for (auto x : c)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    int ans = *rbegin(st) - *begin(st);
    for (int i = 0; i < n; i++)
    {
        st.erase(st.find(c[i].first));
        st.emplace(c[i].second);
        ans = min(ans, *rbegin(st) - *begin(st));
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