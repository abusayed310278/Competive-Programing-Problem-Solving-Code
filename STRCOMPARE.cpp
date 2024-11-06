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
    string a, b;
    cin >> a >> b;
    bool f = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < b[i])
        {
            if (!f)
                f = 1;
        }
        else if (a[i] > b[i])
        {
            if (f)
                f = 0;
        }
        ans += f;
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