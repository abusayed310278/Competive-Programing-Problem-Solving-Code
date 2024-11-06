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
vector<int> start, depth, travel;

void dfs(int node)
{

    start[node] = travel.size();
    travel.push_back(node);

    for (int v : g[node])
    {
        depth[v] = depth[node] + 1;
        dfs(v);
        travel.push_back(node);
    }
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

    depth.resize(n + 1), start.resize(n + 1);
    depth[0] = INT_MAX;

    dfs(1);

    int q;
    cin >> q;
    while (q--)
    {

        int v, u;
        cin >> v >> u;
        int ans = 0;
        for (int i = min(start[v], start[u]); i <= max(start[v], start[u]); i++)
        {
            int node = travel[i];
            if (depth[node] < depth[ans])
            {

                ans = node;
            }
        }

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