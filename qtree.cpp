#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
// #define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

struct Edge {
    int src, nbr, c, i; // v is source and u is destination
    Edge(int v, int u, int _c, int _i) : src(v), nbr(u), c(_c), i(_i) {}
};

vector<vector<Edge>> g;
vector<int> depth, parent, edgetonode, size;
vector<int> head, lt, pos, value, heavy;
int idx;

void dfs(int node) {

    for (Edge e : g[node]) {

        if (e.nbr == parent[node])
            continue;

        depth[e.nbr] = depth[node] + 1;
        parent[e.nbr] = node;
        edgetonode[e.i] = e.nbr;
        value[e.nbr] = e.c;

        dfs(e.nbr);
        size[node] += size[e.nbr];
        if (size[e.nbr] > size[heavy[node]])
            heavy[node] = e.nbr;
    }

    size[node]++;
}

void hld(int node, int h) {
    head[node] = h;
    lt[idx] = node;
    pos[node] = idx++;

    if (heavy[node] != 0)
        hld(heavy[node], h);

    for (Edge e : g[node]) {
        if (e.nbr != parent[node] && e.nbr != heavy[node]) {
            hld(e.nbr, e.nbr);
        }
    }
}

vector<int> tree;

// Segment tree build
int build(int node, int s, int e) {
    if (s == e) {
        return tree[node] = value[lt[s]];
    } else {
        int mid = (s + e) / 2;
        int la = build(2 * node, s, mid);
        int ra = build(2 * node + 1, mid + 1, e);
        return tree[node] = max(la, ra);
    }
}

void update(int node, int s, int e, int pos, int val) {
    if (s == e) {
        tree[node] = val;
    } else {
        int mid = (s + e) / 2;
        if (pos <= mid) {
            update(2 * node, s, mid, pos, val);
        } else {
            update(2 * node + 1, mid + 1, e, pos, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int s, int e, int l, int r) {
    if (e < l || r < s)
        return INT_MIN;

    if (l <= s && e <= r) {
        return tree[node];
    } else {
        int mid = (s + e) / 2;
        return max(query(2 * node, s, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
    }
}

int querylca(int a, int b, int n) {
    int res = INT_MIN;
    while (head[a] != head[b]) {
        // we assume b is greater than a
        if (depth[head[a]] > depth[head[b]]) {
            swap(a, b);
        }
        res = max(res, query(1, 1, n, pos[head[b]], pos[b]));
        b = parent[head[b]];
    }

    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    res = query(1, 1, n, pos[a] + 1, pos[b]);
    return res;
}

void solve() {
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        g[v].push_back(Edge(v, u, c, i));
        g[u].push_back(Edge(u, v, c, i));
    }

    depth.resize(n + 1, 0);
    parent.resize(n + 1, 0);
    edgetonode.resize(n, 0);
    size.resize(n + 1, 0);
    heavy.resize(n + 1);

    dfs(1);
    head.resize(n + 1, 0);
    lt.resize(n + 1, 0);
    pos.resize(n + 1, 0);
    value.resize(n + 1, 0);
    idx = 1;
    hld(1, 1);
    tree.resize(4 * n + 1, 0);
    build(1, 1, n);

    while (true) {
        string s;
        cin >> s;
        if (s[0] == 'D')
            break;

        int a, b;
        cin >> a >> b;

        if (s[0] == 'C') {
            int node = edgetonode[a];
            update(1, 1, n, pos[node], b);
        } else {
            int ans = querylca(a, b, n);
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*
1
3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
*/
