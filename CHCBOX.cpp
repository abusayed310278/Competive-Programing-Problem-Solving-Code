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
    vector<int> a(n + 1);
    int maxi = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }

    vector<int> pos;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == maxi)
            pos.push_back(i);
    }

    pos.push_back(pos[0] + n);

    int sz = n / 2;
    int ans = 0;
    for (int i = 1; i < pos.size(); i++)
    {
        ans += max(0, pos[i] - pos[i - 1] - sz);
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