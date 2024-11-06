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

    int n, x;
    cin >> n >> x;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int si, ri;
        cin >> si >> ri;

        if (si <= x and ans <= ri)
        {
            ans = max(ans, ri);
        }
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