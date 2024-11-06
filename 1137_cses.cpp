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
vector<vector<int>> child;
vector<int> value, lt, start, ent;
vector<long> fn;
int timer;

//euler tour

void dfs(int node, int p)
{

    start[node] = ++timer;
    lt[timer] = value[node];

    for (auto c : child[node])
    {
        if (c == p)
            continue;
        dfs(c, node);
    }

    ent[node] = timer;
}

void addft(int i, long val)
{

    while (i < fn.size())
    {
        fn[i] += val;
        i += (i) & (-i);
    }
}

long sumft(int i)
{

    long sum = 0;
    while (i > 0)
    {

        sum += fn[i];
        i -= (i) & (-i);
    }
    return sum;
}

void buildft()
{

    for (int i = 1; i <= timer; i++)
    {
        addft(i, lt[i]);
    }
}

// https://cses.fi/problemset/task/1137

void solve()
{

    int n, q;
    cin >> n >> q;

    start.resize(n + 1), ent.resize(n + 1), lt.resize(n + 1), value.resize(n + 1);

    child.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
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

    fn.resize(lt.size());
    buildft();

    while (q--)
    {

        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int v, val;
            cin >> v >> val;
            long delta = (long)val - (long)value[v];

            value[v] = val;
            addft(start[v], delta);
            // addft(ent[v],delta);
        }
        else
        {
            int v;
            cin >> v;
            long sum = sumft(ent[v]) - sumft(start[v] - 1);
            // sum /= 2;
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