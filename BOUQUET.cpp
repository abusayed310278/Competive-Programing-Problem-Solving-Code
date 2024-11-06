#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
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
    int a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        int cs = 0;
        for (int j = 0; j < 3; j++)
        {
            cs += a[i][j];
        }
        if (cs % 2 == 0)
            cs--;
        maxi = max(maxi, cs);
    }

    for (int i = 0; i < 3; i++)
    {
        int cs = 0;
        for (int j = 0; j < 3; j++)
        {
            cs += a[j][i];
        }
        if (cs % 2 == 0)
            cs--;
        maxi = max(maxi, cs);
    }

    cout << maxi << endl;
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