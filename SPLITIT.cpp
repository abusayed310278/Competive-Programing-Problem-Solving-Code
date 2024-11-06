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
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a']++;
    }

    if (v[s[n - 1] - 'a'] >= 2)
    {
        cout << "YES\n";
    }
    else
    {

        cout << "NO\n";
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