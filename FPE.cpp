#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F  first
#define S  second
#define pb  push_back

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


inline void cp() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

}

const int mod = 1e9 + 7;
vvi g;
vi val, parent;

void dfs(int u, int par = -1) {

	for (auto child : g[u]) {

		if (child == par)continue;

		parent[child] = u;
		dfs(child, u);
	}

}

int main()
{

	cp();
	int t; cin >> t;
	while (t--) {

		int n; cin >> n;


		val.resize(n + 1);
		for (int i = 1; i <= n; i++)cin >> val[i];
		for (int i = 1; i <= n; i++)cout << val[i] << " ";



		g.resize(n + 1);
		for (int i = 1; i <= n - 1; i++) {
			int u, v; cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}

		parent.resize(n + 1);
		parent[1] = -1;
		dfs(1);

		for (int i = 1; i <= n; i++)cout << val[i] << " ";

	}

	return 0;
}