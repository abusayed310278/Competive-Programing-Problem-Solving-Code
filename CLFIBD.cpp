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
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }

    vector<int> v;
    // v.push_back(0);
    for (auto x : mp)
    {
        v.push_back(x.second);
    }

    sort(begin(v), end(v));

    string ans = "Dynamic";
    for (int i = 2; i < v.size(); i++)
    {

        if (i == 3)
        {
            if (v[3] != (v[2] + v[1]) and v[3] != (v[2] + v[0]))
                ans = "Not";
        }
        else if (v[i] != (v[i - 1] + v[i - 2]))
            ans = "Not";
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