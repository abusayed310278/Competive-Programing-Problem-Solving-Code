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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> zero(k, 0), one(k, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            one[i % k]++;
        else
            zero[i % k]++;
    }

    ll ans0 = 0, ans1 = 0, flag = 1;
    for (int i = 0; i < k; i++)
    {
        if (one[i] == 0)
            flag = 0;

        // to make all one
        ans0 += one[i] / 2;
        if (one[i] & 1)
            ans0 += 2;

        // to make all one
        ans1 += zero[i];
    }

    ll ans = ans0;
    if (flag)
        ans = min(ans0, ans1);

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