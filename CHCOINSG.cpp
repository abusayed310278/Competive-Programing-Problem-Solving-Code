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
    int n;
    cin >> n;
    if (n % 6 == 0)
    {
        cout << "Misha\n";
    }
    else
    {
        cout << "Chef\n";
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