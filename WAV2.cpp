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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(begin(a), end(a));

    while (q--)
    {
        int x;
        cin >> x;
        int pos = lower_bound(begin(a), end(a), x) - begin(a);

        if (pos < n and a[pos] == x)
        {
            cout << 0 << endl;
            // continue;
        }
        else if (pos & 1)
        {
            cout << "NEGATIVE" << endl;
            // continue;
        }
        else
        {
            cout << "POSITIVE" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}