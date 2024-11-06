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
const int LOGN = 20;
vector<int> g[N];
int sub[N], nn, U[N], v[N], W[N], deleted[N];
int par[N], level[N], dist[LOG][N];

int adj(int x, int e) { return U[e] ^ V[e] ^ x; }

void dfs1(int u, int p)
{
    sub[u] = 1;
    nn++;
    for (auto e : g[u])
    {
        int w = adj(u, e);
        if (w != p and !deleted[e])
            dfs1(w, u), sub[u] += sub[w];
    }
}

int find_centroid(int u, int p)
{
    for (auto e : g[u])
    {
        if (deleted[e])
            continue;
        int w = adj(u, e);
        if (w != p and sub[w] > nn / 2)
            return find_centroid(w, u);
    }
    return u;
}

void add_edge_centroid_tree(int parent, int child)
{
    par[child] = parent;
    level[child] = level[parent] + 1;
}

void dfs2(int u, int p, int lvl)
{
    for (auto e : g[u])
    {
        int w = adj(u, e);
        if (w == p || deleted[e])
            continue;
        dist[lvl][w] = dist[lvl][u] + w[e];
        dfs2(w, u, lvl);
    }
}

void decompose()
{

    nn = 0;
    dfs1(root, root);
    int centroid = find_centroid(root, root);

    if(p==-1 )p=root;
    add_edge_centroid_tree(p,centroid);
    dfs2(centroid,centroid,level[centroid]);

    for(auto e:g[centroid]){
        if(deleted[e])continue;
        deleted[e]=1;
        int w=adj(centroid,e);
        decompose(w,centroid);
    }


}

int compute_distance(int x,int y){
    int lca_level=0;

    for(int i=x,j=y;(lca_level==level[i]) and i!=j;level[i]<level[j]?(j==par[j]):(i==pa[i]));

    return dist[lca_level][x]+dist[lca_level][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> U + i >> V + i >> W + i;
        U[i]++;
        V[i]++;
        g[U[i]].push_back(i);
        g[V[i]].push_back(i);
    }

    decompose(1);
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << compute_distance(x + 1, y + 1) << endl;
    }

    return 0;
}