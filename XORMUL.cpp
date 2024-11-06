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
    int n, a, b;
    cin >> n >> a >> b;
    int c = 0;
    bool ok = true;
    for (int i = n - 1; i >= 0; i--)
    {
        if (((1 << i) & a) == ((1 << i) & b))
        {
            if (((1 << i) & a) == 0)
                c += (1 << i);
        }
        else if (ok)
        {
            if (((1 << i) & b))
                c += (1 << i);
            ok = false;
        }
        else
        {
            if (((1 << i) & a))
                c += (1 << i);
        }
    }
    cout << c << endl;
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