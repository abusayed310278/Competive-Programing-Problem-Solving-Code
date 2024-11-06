#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long

#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int m = sqrt(n) + 1;
    vector<int> SQRT(m + 1, INT_MAX);
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        SQRT[i / m] = min(a[i], SQRT[i / m]);
    }

    int q;
    cin >> q;
    while (q--)
    {

        int l, r;
        int ans=INT_MAX;
        cin >> l >> r;
        for (int i = l; i <= r;)
        {
            if (i % m == 0 and i + m - 1 <= r)
            {
                ans = min(ans, SQRT[i / m]);
                i += m;
            }
            else
            {
                ans = min(ans, a[i]);
                i++;
            }
        }
        cout << ans << endl;
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