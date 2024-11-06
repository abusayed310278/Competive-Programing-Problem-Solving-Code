#include<bits/stdc++.h>
using namespace std;

class Solution
{
	int v,e;
	bool *visited;
	bool *vis;
	list<int>*g,*rev_graph;
	// vector<int>stack;
	stack<int>s;
public:
	Solution(int vertex,int edges){
		this->v=vertex;
		this->e=edges;
		g=new list<int>[v];
		rev_graph=new list<int>[v];
		visited=new bool[v]{false};
		//vis=new bool[v]{false};
	}

	void addEdge(int x,int y){
		g[x].push_back(y);
		rev_graph[y].push_back(x);
	}

	void dfs(int i){
		visited[i]=true;
		for(auto nbr:g[i])
		{
			if(!visited[nbr]){
				dfs(nbr);
			}
			
		}
		
		// stack.push_back(i);
		s.push(i);
	}

	void dfs2(int i){
		visited[i]=true;
		cout<<i<<" ";
		for(auto nbr:rev_graph[i]){
			if(!visited[nbr])dfs2(nbr);
		}
		
	}

	void solve(){
		for(int i=0;i<v;i++){
			if(!visited[i])dfs(i);
		}

		memset(visited,0,v);

		char cnt='A';

		/*for(int x=stack.size()-1;x>=0;x--){
			int node=stack[x];
			if(!visited[node]){
				cout<<cnt<<"->";
				dfs2(node,visited,rev_graph);
				cout<<endl;
				cnt++;
			}
		}*/

		while(!s.empty()){
			int curnode=s.top();s.pop();
			if(!visited[curnode]){
				cout<<cnt<<"->";
				dfs2(curnode);
				cout<<endl;
				cnt++;
			}
		}
		
	}

};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int v,e;cin>>v>>e;

	Solution ob(v,e);

	while(e--){
		int x,y;cin>>x>>y;
		ob.addEdge(x,y);
	}

	ob.solve();

	return 0;
}

/*
v e
7 8
1 0
0 2
2 1
0 3
3 5
5 6
6 3
3 4



*/