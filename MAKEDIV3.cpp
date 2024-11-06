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
const int N = 1e4 + 1;


void solve()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == n)
            cout << 3;
        else
            cout << 0;
    }
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