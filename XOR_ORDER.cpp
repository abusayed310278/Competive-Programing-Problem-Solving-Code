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
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for (int i = 29; i >= 0; --i)
    {
        int x = (1 << i) ^ a;
        int y = (1 << i) ^ b;
        int z = (1 << i) ^ c;
        
        if (x < y && y < z)
        {
            a = x;
            b = y;
            c = z;
            ans ^= (1 << i);
            break;
        }
        else if (x < min(y, z) || max(x, y) < z)
        {
            a = x;
            b = y;
            c = z;
            ans ^= (1 << i);
        }
    }
    if (a < b && b < c)
        cout << ans<<endl;
    else
        cout << -1<<endl;
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
        // cout<<endl;
    }

    return 0;
}