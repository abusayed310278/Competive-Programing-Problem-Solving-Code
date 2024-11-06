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
const int N = 1e5 + 10;
int parent[N];
vector<int> g[N];

void dfs(int u, int par = -1)
{

    parent[u] = par;
    for (auto child : g[u])
    {
        if (child == par)
            continue;
        dfs(child, u);
    }
}

vector<int> path(int v)
{

    vector<int> ans;

    while (v != -1)
    {
        ans.push_back(v);
        v = parent[v];
    }

    reverse(begin(ans), end(ans));
    return ans;
}

void solve()
{

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    int u, v;
    cin >> u >> v;
    vector<int> x_path = path(u);
    vector<int> y_path = path(v);
    int mini_length = min(x_path.size(), y_path.size());

    int lca = -1;

    
    for (int i = 0; i < mini_length; i++)
    {

        if (x_path[i] == y_path[i])
        {
            lca = x_path[i];
        }
        else
        {
            break;
        }
    }

    cout << lca << endl;


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