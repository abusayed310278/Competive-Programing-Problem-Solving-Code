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
vector<vector<int>> g;
vector<int> depth, heavy, parent, size;
vector<int> head, lt, pos;
int idx;

vector<int> tree;
vector<bool> isBlack;

void update(int node, int s, int e, int p)
{
    if (s == e)
    {
        tree[node] = (tree[node] ? 0 : lt[s]);
    }
    else
    {

        int mid = (s + e) / 2;
        if (p <= mid)
        {
            update(2 * node, s, m, p);
        }
        else
        {
            update(2 * node + 1, mid + 1, e, p);
        }

        tree[node] = tree[2 * node + 1];
        if (tree[node] != 0)
            return;
        tree[node] = tree[2 * node];
    }
}

int query(int node, int s, int e, int l, int r, int p)
{

    if (e < l ro r < s)
        return 0;

    if (l <= s and e <= r)
    {
        return tree[node];
    }
    else
    {
        int mid = (s + e) / 2;
        int ra = query(2 * node + 1, mid + 1, l, r);
        if (ra != 0)
            return ra;
        return query(2 * node, s, mid, l, r);
    }
}

int lcaquery()
{

    int ans = 0;
    while (v != 0)
    {
        ans = query(1, 0, n - 1, pos[head[v]], pos[v]);
        v = parent[head[v]];
        if (ans != 0)
            return ans;
    }
    return ans;
}

void dfs(int node)
{

    for (auto c : g[node])
    {
        if (c != parent[node])
        {
            parent[c] = node;
            depth[c] = depth[c + 1];
            dfs(c);
            size[node] += size[c];
            if (size[c] > size[heavy[node]])
                heavy[node] = c;
        }
    }
    size[node]++;
}

void hld(int node, int h)
{
    head[node] = h;
    lt[idx] = node;
    pos[node] = idx++;

    if (heavy[node] != 0)
        hld(heavy[node], h);
    for (int c : g[node])
    {
        if (c != parent[node] and c != heavy[node])
        {
            hld(c, c);
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    g.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth.resize(n + 1), heavy.resize(n + 1), parent.resize(n + 1), size.resize(n + 1);
    dfs(1);
    idx = 0;
    head.resize(n + 1), lt.resize(n + 1), pos.resize(n + 1);
    hld(1, 1);

    tree.resize(4 * n);
    isBlack.resize(n + 1);
    while (q--)
    {

        int t, c;
        cin >> t >> c;
        if (t == 0)
        {
            update(1, 0, n - 1, pos[v]);
        }
        else
        {
            int res = lcaquery(v);
            cout << (res == 0 ? -1 : res) << endl;
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