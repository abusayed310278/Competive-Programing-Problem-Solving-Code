#include<bits/stdc++.h>
using namespace std;
#define inf 1e5+10

//using code for striver
struct node {
	int u, v, w;
	node(int _u, int _v, int _w) {
		u = _u; v = _v; w = _w;
	}

};



int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<node>edges;
	int n, m; //n=vertex,m=edges
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(node(u, v, w));
	}

	vector<int>dist(n, inf);
	int src = 0;
	dist[src] = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (auto it : edges) {
			if (dist[it.u] + it.w < dist[it.v])
				dist[it.v] = dist[it.u] + it.w;
		}
	}

	int flag = 0;
	for (auto it : edges) {
		if (dist[it.u] + it.w < dist[it.v]) {
			cout << "Negative edges.";
			flag = 1;
			break;
		}
	}

	if (!flag) {
		for (int i = 0; i < n; i++) {
			cout << dist[i] << " ";
		}
	}

	return 0;
}


/*

6 7
0 1 5
1 2 -2
1 5 -3
2 4 3
3 2 6
3 4 -2
5 3 1



*/