#include <bits/stdc++.h>
#define endl "\n"
#define int long long
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
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    k -= n;

    vector<int> ans;
    while (k >= cnt)
    {
        ans.push_back(cnt + 1);
        k -= cnt;
        cnt++;
    }

    while (ans.size() < n)
    {
        ans.push_back(cnt - k);
    }

    for (auto i : ans)
        cout << i << " ";

    cout << endl;
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