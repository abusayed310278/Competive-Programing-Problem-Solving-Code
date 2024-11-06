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
vector<vector<pair<int, int>>> g;
const int maxbit = 17;
vector<vector<int>> table;
vector<long> node2rootwt;
vector<int> level, maxchild;

long max(long a, long b)
{
    return a > b;
}

long dfs(int u, long sum, int p)
{

    node2rootwt[u] = sum;
    table[0][u] = p;

    long maxi = 0;
    for (auto child : g[u])
    {
        if (child.first != p)
        {

            level[child.first] = level[u] + 1;
            long m = dfs(child.first, child.second + sum, u);
            maxi = max(maxi, max(child.second, m + child.second));
        }
    }
    maxchild[u] = maxi;
    return maxi;
}

void build(int n)
{

    for (int i = 1; i <= maxbit; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int lca(int u, int v)
{

    if (level[u] > level[v])
        swap(u, v);

    // we assume level of v is greater than u
    int k = level[v] - level[u];
    for (int i = maxbit; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            v = table[i][v];
        }
    }

    if (u == v)
        return u;

    for (int i = maxbit; i >= 0; i--)
    {
        int up = table[i][u];
        int vp = table[i][v];
        if (up != vp)
        {
            u = up;
            v = vp;
        }
    }

    return table[0][u];
}

void solve()
{

    int n, q;
    cin >> n >> q;
    g.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    maxchild.resize(n + 1);
    level.resize(n + 1);
    node2rootwt.resize(n + 1);
    table.resize(maxbit+1, vector<int>(n + 1));
    dfs(1, 0, 0);

    build(n);

    while (q--)
    {
        int u, v, x;
        cin >> u >> v >> x;

        int lc = lca(u, v);
        long lcasum = node2rootwt[u] - node2rootwt[lc] + node2rootwt[v] - node2rootwt[lc];
        long esum = maxchild[u] + maxchild[v] + x;

        long ans = max(lcasum, esum);

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