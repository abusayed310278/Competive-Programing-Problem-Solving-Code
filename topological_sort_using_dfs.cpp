#include<bits/stdc++.h>
using namespace std;

class Graph
{
	list<int>*l;
	bool *visited;
	int v,e;
	stack<int>st;
public:
	Graph(int v,int e){
		this->v=v;
		this->e=e;
		visited=new bool[v]{false};
	}
    void addEdge(int x,int y)
	{
		l[x].push_back(y);
		
	}
	
	void dfs(int u)
	{
		visited[u]=true;
		for(auto nbr:l[u])
		{
			if(!visited[nbr])
				dfs(nbr);
		}
		st.push(u);

	}


	void solve()
	{
			
		for(int i=0;i<v;i++){
			if(!visited[i]){
				dfs(i);
			}
		}

		while(!st.empty()){
			int item=st.top();
			cout<<item<<" ";
			st.pop();
		}
		
	}	
	
};

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int v,e;cin>>v>>e;

	Graph g(v,e);

	for(int i=1;i<=e;i++){
		int x,y;cin>>x>>y;
		g.addEdge(x,y);
	}

	g.solve();
	
	
	return 0;	
}

/*

5
0 1
1 3
3 4
2 3
2 4

*/