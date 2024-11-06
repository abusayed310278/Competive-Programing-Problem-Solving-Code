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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    sort(begin(a), end(a));

    int req = m - 1, dougnuts = 0;
    for (int i = 0; i < m; i++)
    {
        int p = m - i - 1;
        dougnuts += a[i];

        if (dougnuts >= p - 1)
        {
            if (dougnuts == p - 1)
                cout << p - 1 << endl;
            else
                cout << p << endl;
            break;
        }
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