#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long int
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
    ll sum = n * (n + 1) / 2;
    if (k < sum)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        for (int i = 1; i < n; i++)
            cout << 1 << " ";
    }
    k = k - (sum - 1);
    cout << k << endl;
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