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
    int n, x;
    cin >> n >> x;
    if (2 * x - 1 > n)
    {
        cout << -1 << endl;
        return;
    }

    string ans = string(n, 'a');
    for (int i = 1; i < x; i++)
    {
        ans[i - 1] = 'a' + i;
        ans[n - i] = 'a' + i;
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