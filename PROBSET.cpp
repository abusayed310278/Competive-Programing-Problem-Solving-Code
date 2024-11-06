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
    int x;
    cin >> x;
    if (x <= 250000)
    {
        cout << x << endl;
    }
    else if (x >= 250001 and x <= 500000)
    {
        cout << x - x * .05 << endl;
    }
    else if (x >= 500001 and x <= 750, 000)
    {
        cout << x - x * .10 << endl;
    }
    else if (x >= 750001 and x <= 1000000)
    {
        cout << x - x * .15 << endl;
    }
    else if (x >= 1000001 and x <= 1250000)
    {
        cout << x - x * .20 << endl;
    }
    else if (x >= 1250001 and x <= 1500000)
    {
        cout << x - x * .25 << endl;
    }
    else if (x > 1500000)
    {
        cout << x - x * .30 << endl;
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