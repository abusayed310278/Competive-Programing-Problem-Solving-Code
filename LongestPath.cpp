#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F  first
#define S  second
#define pb  push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;





const int mod = 1e9 + 7;
vvi g;
vi val;


int dfs(int u) {


	if (val[u])return val[u];
	for (auto x : g[u]) {

		val[u] = max(val[u], 1 + dfs(x));
	}
	return val[u];
}


void solve() {

	int n, m; cin >> n >> m;
	g.resize(n + 1);
	val.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dfs(i));
	}

	cout << ans << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}