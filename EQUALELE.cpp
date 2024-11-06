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
    int n;
    cin >> n;
    vector<int> fre(n + 1);

    int maxi = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        fre[x]++;
        maxi = max(maxi, fre[x]);
    }

    if (maxi > 1)
    {
        cout << n - maxi << endl;
    }
    else
    {
        cout << n - 1 << endl;
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