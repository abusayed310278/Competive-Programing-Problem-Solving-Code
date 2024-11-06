#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//kosaraju algorithms

vector<int> SCC; // SCC[i] stores the SCC to which node i belongs
vector<vector<int>> adjList, invAdjList;
vector<bool> visited;
int N;

/*
Graph:
	0 <---- 1 <---- 2 <---- 7
	|		^	    |		^
    \/		|	    \/		|
    3 ----> 4 <---- 5 ----> 6
*/

// Step 1
void dfsSCC(int node, stack<int> & S) {
	visited[node] = true;
	for (int neighbour: adjList[node]) {
		if (!visited[neighbour])
			dfsSCC(neighbour, S);
	}
	S.push(node);
}

stack<int> getStack() {
	stack<int> S;
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i])
			dfsSCC(i, S);
	}
	return S;
}

// Step 2
void invertGraph() {
	invAdjList.assign(N, vector<int>());
	for (int i = 0; i < N; i++) {
		for (int u: adjList[i]) {
			invAdjList[u].push_back(i);
		}
	}
}

// Step 3
void dfsCC(int node, int cnt) {
	// dfs function from the connected components video
	SCC[node] = cnt;
	for (int neighbour: invAdjList[node]) {
		if (SCC[neighbour] == -1)
			dfsCC(neighbour, cnt);
	}
}

void findSCCs(stack<int> & S) {
	SCC.assign(N, -1);
	int numSCCs = 0, curNode;
	while (!S.empty()) {
		curNode = S.top();
		S.pop();
		if (SCC[curNode] == -1) {
			dfsCC(curNode, numSCCs);
			numSCCs++;
		}
	}
}

// Problem solver
void SCCs() {
	// only adjList must have been declared and initialised before calling SCCs
	N = (int) adjList.size();
	// Step 1: DFS storing each node after visiting its connections
	stack<int> S = getStack();
	// Step 2: Invert the graph
	invertGraph();
	// Step 3: DFS to get the components
	findSCCs(S);
}

int main() {
	adjList = {{3}, {0}, {1, 5}, {4}, {1}, {4, 6}, {7}, {2}};
	SCCs();
	for (int i = 0; i < N; i++)
		cout << i << ", SCC: " << SCC[i] << '\n';
	return 0;
}


/*

scc is 2:

component 1: 0 1 3 4
component 2: 2 5 6 7


*/