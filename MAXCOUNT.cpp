#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#include <unordered_map>

void solve()
{
    int n;
    cin >> n;
    int v[n];
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    int f = v[0];
    int maxi = mp[v[0]];

    for (auto it : mp)
    {
        if (it.second > maxi)
        {
            maxi = it.second;
            f = it.first;
        }
        if (it.second == maxi)
        {
            f = (it.first < f) ? it.first : f;
        }
    }
    cout << f << " " << maxi << endl;
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}