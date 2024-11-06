#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int>g[N];
int depth[N];

void dfs(int vertex, int par = -1)
{
	for (auto child : g[vertex])
	{
		if (child == par)continue;
		depth[child] = depth[vertex] + 1;
		dfs(child, par);
	}
}





int main() {


	freopen("inputf.in", "r", stdin);
	// freopen("outputf.in","w",stdout);
	int n; cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);

	}
	memset(depth, 0, sizeof(depth));

	dfs(1);
	int mx_depth = -1, mx_d_node;

	for (int i = 1; i <= n; i++) {
		if (mx_depth < depth[i]) {
			mx_depth = depth[i];
			mx_d_node = i;
		}
		depth[i] = 0;
	}

	dfs(mx_d_node);
	for (int i = 1; i <= n; i++) {
		if (mx_depth < depth[i]) {
			mx_depth = depth[i];
		}
	}
	cout << mx_depth << endl;

	return 0;
}

/*

13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

*/