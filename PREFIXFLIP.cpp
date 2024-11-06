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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> ps(n, 0);
    ps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        ps[i] = ps[i - 1];
        if (s[i] != s[i - 1])
            ps[i]++;
    }

    int ans = INT_MAX;
    for (int i = 0; i <= n - k; i++)
    {
        if (s[i + k - 1] == '1')
            ans = min(ans, ps[i + k - 1] - ps[i]);
        else
            ans = min(ans, ps[i + k - 1] - ps[i] + 1);
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