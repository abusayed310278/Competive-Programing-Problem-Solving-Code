#include <bits/stdc++.h>
using namespace std;
#define int long long int

int MAX_BIT = 20;
vector<int> a;
vector<pair<int, int>> info;
vector<int> p;
vector<vector<int>> g;
vector<vector<int>> anc;

void dfs(int node, int mx, int cnt)
{
    if (a[node] > mx)
    {
        mx = a[node];
        cnt++;
    }
    info[node] = {mx, cnt};
    for (auto adjnode : g[node])
    {
        dfs(adjnode, mx, cnt);
    }
}

void build(int n)
{
    anc = vector<vector<int>> (MAX_BIT, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        anc[0][i] = p[i];
    }
    for (int i = 1; i < MAX_BIT; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
}

int calc(int u, int w)
{
    int cnt = info[u].second;
    for (int i = MAX_BIT - 1; i >= 0; i--)
    {
        if (w < info[anc[i][u]].first)
        {
            u = anc[i][u];
        }
    }
    u = p[u];
    return cnt - info[u].second;
}

void Medicine_King()
{
    int n;
    cin >> n;
    a = vector<int> (n+1,0);
    info = vector<pair<int, int>>(n+1,{0,0});
    p = vector<int> (n+1,0);
    g = vector<vector<int>> (n+1);
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    dfs(1,0,0);
    build(n);
    int q;
    cin >> q;
    int pr = 0;
    while (q--)
    {
        int u, w;
        cin >> u >> w;
        u = pr ^ u;
        w = pr ^ w;
        if (info[u].first <= w)
        {
            pr = 0;
            cout << 0 << endl;
            continue;
        }
        pr = calc(u, w);
        cout << pr << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        Medicine_King();
    }
    return 0;
}