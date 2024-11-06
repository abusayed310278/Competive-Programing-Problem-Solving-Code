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
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    for (auto x : freq)
    {
        if (x.second % x.first != 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    map<int, int> m, f;
    for (int i = 0, j = 1; i < n; i++)
    {
        if (m.find(a[i]) == m.end() or f[a[i]] == 0)
        {
            m[a[i]] = j++;
            f[a[i]] = a[i];
        }
        cout << m[a[i]] << " ";
        f[a[i]]--;
    }

    cout << endl;
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