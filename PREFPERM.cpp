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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    a.insert(begin(a), 0);

    vector<int> p(n);
    iota(begin(p), end(p), 1);
    for (int i = 1; i <= k; i++)
    {
        reverse(begin(p) + a[i - 1], begin(p) + a[i]);
    }

    for (auto x : p)
    {
        cout << x << " ";
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