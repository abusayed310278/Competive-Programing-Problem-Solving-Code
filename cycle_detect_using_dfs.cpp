#include<bits/stdc++.h>
using namespace std;

//undirected graph
class Graph {
	int n;
	list<int>*l;
public:
	Graph(int n) {
		this->n = n;
		l = new list<int>[n];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);

	}

	void printAdjList() {
		for (int i = 0; i < n; i++) {
			cout << i << "->";
			for (auto node : l[i]) {
				cout << node << ",";
			}
			cout << endl;
		}
	}

	bool dfs(int node, vector<bool>&visited, int parent) {

		visited[node] = true;

		for (auto nbr : l[node]) {
			if (!visited[nbr]) {
				bool cycle_found = dfs(0, visited, node);
				if (cycle_found)return true;
			} else if (nbr != parent)return true;
		}
		return false;
	}

	bool contains_cycle() {
		vector<bool>visited(n, false);
		return dfs(0, visited, -1);
	}


};

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
	int n; cin >> n;
	Graph g(n);

	while (n--) {
		int x, y; cin >> x >> y;
		g.addEdge(x, y);
	}

	cout << g.contains_cycle();
	return 0;
}


/*

3
0 1
1 2
2 0

*/