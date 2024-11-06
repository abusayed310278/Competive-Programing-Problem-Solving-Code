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
vector<int> parent, depth, heavy, size;
vector<int> head, lt, pos;

int idx;

void dfs(int u)
{

    for (int c : g[u])
    {

        depth[c] = depth[u] + 1;
        parent[c] = u;
        dfs(c);

        size[u] += size[c];
        if (size[c] > size[heavy[u]])
        {
            heavy[u] = c;
        }
    }

    size[u]++;
}

void hld(int u, int chain)
{

    head[u] = chain;
    // lt[idx]=value[node];
    pos[u] = idx++;
    // idx++;

    if (heavy[u] != 0)
    {
        hld(heavy[u], chain);
    }

    for (int c : g[u])
    {
        if (heavy[u] != c)
        {
            hld(c, c);
        }
    }
}

int lca(int a, int b)
{

    while (head[a] != head[b])
    {

        // we assume a is greater than b so we swap them
        if (depth[head[a]] < depth[head[b]])
            swap(a, b);

        a = parent[head[a]];
    }

    if (depth[a] < depth[b])
        swap(a, b);

    return b;
}

void solve()
{

    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++)
        {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }

    parent.resize(n + 1); depth.resize(n + 1); size.resize(n + 1); heavy.resize(n + 1);

    dfs(1);
    head.resize(n + 1); lt.resize(n + 1); pos.resize(n + 1); idx = 1;
    hld(1, 1);

    /*cout<<"heavy:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": "<<size[i]<<endl;
    }*/

    /*cout<<"size:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": "<<size[i]<<endl;
    }*/

    int q;
    cin >> q;
    while (q--)
    {

        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
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

/*

1
7
3 2 3 4
0
3 5 6 7
0
0
0
0
2
5 7
2 7



*/