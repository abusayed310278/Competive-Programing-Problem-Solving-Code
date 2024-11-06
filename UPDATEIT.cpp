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
vector<int> fn;
int n;

void update(int i, int val)
{

    while (i <=n)
    {

        fn[i] += val;
        i += (i) & (-i);
    }
}

int query(int i)
{

    int res = 0;
    while (i > 0)
    {
        res += fn[i];
        i -= (i) & (-i);
    }
    return res;
}

void solve()
{

    int u;
    cin >> n >> u;
    fn.resize(n + 1, 0);

    for (int i = 1; i <= u; i++)
    {
        int l, r, val;
        cin >> l >> r >> val;
        // l++, r++;
        update(l + 1, val);
        update(r + 2, -val);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {

        int idx;
        cin >> idx;
        // idx++;
        cout << query(idx + 1) << endl;
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