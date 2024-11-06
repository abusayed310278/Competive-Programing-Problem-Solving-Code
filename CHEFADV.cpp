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

int x, y;
int f(int n, int m)
{
}

void solve()
{
    // Write your solution code here
    ll n, m;
    cin >> n >> m >> x >> y;

    if ((n == 1 and m == 1) or (n == 2 and m == 2))
    {
        cout << "Chefirnemo\n";
    }
    else
    {

        if ( ((n - 1) % x == 0 and (m - 1) % y == 0 and (n - 1) >= 0 and (m - 1) >= 0) or ((n - 2) % x == 0 and (m - 2) % y == 0 and (n - 2) >= 0 and (m - 2) >= 0) )
        {
            cout << "Chefirnemo\n";
        }
        else
        {
            cout << "Pofik\n";
        }
    }
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