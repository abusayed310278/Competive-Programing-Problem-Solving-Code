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
    int k = 2;
    vector<int> v1(26, 0), v2(26, 0);
    while (k--)
    {
        string s;
        cin >> s;
        for (char c : s)
        {
            v1[c - 'a']++;
        }
    }

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        for (char c : s)
        {
            v2[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (v2[i] > v1[i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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