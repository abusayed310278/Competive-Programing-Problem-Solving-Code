#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];

int make(int u) {
	parent[u] = u;
	size[u] = 1;
}

int find(int u) {
	if (u == parent[u])return u;

	return parent[u] = find(parent[u]);
}

void Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {

		if (size[u] > size[v]) {
			swap(size[u], size[v]);
		}
		parent[v] = u;
		size[u] += size[v];
	}
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
	int n, m;
	vector < pair<int, pair<int, int>>>edges;
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({wt, {u, v}});
	}
	sort(edges.begin(), edges.end());

	for(int i=1;i<=n;i++){
		make(i);
	}

	int cost=0;
	for(auto &edge:edges){
		int wt=edge.first;
		int u=edge.second.first;
		int v=edge.second.second;

		if(find(u)==find(v))continue;
		Union(u,v);
		cost+=wt;
		cout<<u<<" "<<v<<endl;

	}
	cout<<cost<<endl;

	return 0;
}

/*

6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7

*/