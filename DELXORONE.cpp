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
    vector<int> fr(n + 2, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ++fr[x];
    }

    int ans = n;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, n - fr[i] - fr[i ^ 1]);
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