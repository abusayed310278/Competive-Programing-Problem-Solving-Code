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
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    int con = 0, ans = -1, maxi = INT_MIN;
    for (auto x : mp)
    {
        con = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (x.first == a[i] and x.first == a[i + 1])
            {
                i++;
                con++;
            }
        }
        con = x.second - con;
        if (con > maxi)
        {
            maxi = con;
            ans = x.first;
        }
    }

    cout << ans << endl;
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