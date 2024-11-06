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

int diff(int a, int b)
{

    return abs(a - b);
}

void solve()
{
    // Write your solution code here
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }

    sort(begin(a), end(a));

    if ((a[0] % 2 != a[1] % 2) or (a[2] % 2 != a[0] % 2))
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (a[1] + a[2] - 2 * a[0]) / 2 << endl;
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