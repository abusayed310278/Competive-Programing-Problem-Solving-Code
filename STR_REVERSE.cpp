#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

int prefix(string rev, string s)
{
    int i = 0, j = 0, len = 0;

    while (j < s.size())
    {
        if (rev[i] == s[j])
        {
            i++;
            len++;
        }
        j++;
    }

    return len;
}

void solve()
{
    // Write your solution code here
    string s;
    cin >> s;
    string rev = s;
    reverse(begin(rev), end(rev));

    int sz = s.size();
    int ans = sz - prefix(rev, s);

    cout << ans << endl;
}

int32_t main()
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