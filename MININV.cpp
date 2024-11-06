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
    vector<int> a(n);

    map<int, int> left, right;
    for (auto &x : a)
    {
        cin >> x;
        left[x]++;
    }

    ll ans = 0, cur_inv = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ll l = left[a[i] + 1];
        ll r = right[a[i] - 1];
        cur_inv += l - r;
        ans = max(ans, cur_inv);
        --left[a[i]];
        ++right[a[i]];
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