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
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] != b[i])
        {
            while (i < n and a[i] != b[i])
            {
                i += 2;
            }
            ans++;
        }
    }

    for (int i = 1; i < n; i += 2)
    {

        if (a[i] != b[i])
        {
            while (i < n and a[i] != b[i])
            {
                i += 2;
            }
            ans++;
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