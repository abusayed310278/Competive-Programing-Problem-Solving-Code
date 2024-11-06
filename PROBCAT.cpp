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
    int x;
    cin >> x;
    if (x >= 1 and x < 100)
    {
        cout << "Easy\n";
    }
    else if (x >= 100 and x < 200)
    {
        cout << "Medium\n";
    }
    else if (x >= 200 and x <= 300)
    {
        cout << "Hard\n";
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