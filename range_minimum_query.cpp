#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
// #define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

vector<vector<int>> table;
void build(int n, vector<int> &a)
{

    int k = log2(n);
    table.resize(k + 1, vector<int>(n));
    table[0] = a;
    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int query(int l, int r)
{

    int count = r - l + 1;
    int k = log2(count);

    return min(table[k][l], table[k][r - (1 << k) + 1]);
}

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(n, a);
    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
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