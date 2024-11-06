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

vector<vector<int>> child;
vector<int> color, lt, start, ent;
vector<long> fn;
int timer;

//euler tour

void dfs(int node, int p)
{

    start[node] = ++timer;
    lt[timer] = color[node];

    for (auto c : child[node])
    {
        if (c == p)
            continue;
        dfs(c, node);
    }

    ent[node] = timer;
}

vector<long> tree, lazy;
static long one = 1;

void propagete(int node, int s, int e)
{

    if (lazy[node] == 0)
        return;

    tree[node] = one << lazy[node];

    if (s != e)
    {
        lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int s, int e)
{

    if (s == e)
    {
        tree[node] = one << lt[s];
    }
    else
    {

        int mid = (s + e) / 2;
        build(2 * node, s, mid);
        build(2 * node + 1, mid + 1, e);

        tree[node] = tree[2 * node] | tree[2 * node + 1];
    }
}

void update(int node, int s, int e, int l, int r, int c)
{
    propagete(node, s, e);
    if (e < l or r < s)
        return;

    if (s == e)
    {
        lazy[node] = c;
        propagete(node, s, e);
    }
    else
    {

        int mid = (s + e) / 2;
        update(2 * node, s, mid, l, r, c);
        update(2 * node + 1, mid + 1, e, l, r, c);

        tree[node] = tree[2 * node] | tree[2 * node + 1];
    }
}

long query(int node, int s, int e, int l, int r)
{

    if (e < l or r < s)
        return 0;

    propagete(node, s, e);

    if (l <= s and e <= r)
    {
        return tree[node];
    }
    else
    {
        int mid = (s + e) / 2;
        return query(2 * node, s, mid, l, r) | query(2 * node + 1, mid + 1, e, l, r);
    }
}

// https://codeforces.com/problemset/problem/620/E

void solve()
{

    int n, q;
    cin >> n >> q;

    start.resize(n + 1), ent.resize(n + 1), lt.resize(n + 1), color.resize(n + 1);

    child.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        child[u].push_back(v);
        child[v].push_back(u);
    }

    timer = 0;
    dfs(1, 0);

    tree.resize(4 * n + 5), lazy.resize(4 * n + 5);
    build(1, 1, n);

    while (q--)
    {

        int ty, v;
        cin >> ty >> v;

        if (ty == 1)
        {
            int c;
            cin >> c;

            update(1, 1, n, start[v], ent[v], c);
        }
        else
        {
            long ans = query(1, 1, n, start[v], ent[v]);

            int count = 0;
            while (ans > 0)
            {
                count++;
                ans -= ans & (-ans);
            }

            cout << count << endl;
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