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
vector<int> value, start, ent, lt, fn;
vector<vector<int>> child;
int timer;

void dfs(int node)
{
    lt[timer] = value[node];
    start[node] = timer++;

    for (int c : child[node])
    {
        dfs(c);
    }
    lt[timer] = -value[node];
    ent[node] = timer++;
}

void add(int i, int val)
{
    while (i < fn.size())
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

void build()
{

    for (int i = 1; i < lt.size(); i++)
    {
        add(i, lt[i]);
    }
}

void solve()
{

    int n;
    cin >> n;
    value.resize(n + 1), child.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> value[i];

    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        child[p].push_back(i);
    }

    timer = 1;
    start.resize(n + 1), ent.resize(n + 1), lt.resize(2 * n + 1);

    dfs(1);
    build();

    int q;
    cin >> q;
    while (q--)
    {
        int t, i;
        cin >> t >> i;
        if (t == 1)
        {
            int val;
            cin >> val;
            add(start[i], -value[i] + val);
            add(ent[i], +value[i] - val);
            value[i] = val;
        }
        else
        {
            int sum = query(start[i]);
            cout << sum << endl;
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