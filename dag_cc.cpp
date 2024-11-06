#include<bits/stdc++.h>

using namespace std;
class Graph
{
	map<int,<list<int> >l;
	int N;
public:
	
	static int visited[N]={false};
    void addEdge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
		
	}
	
	bool dfsRec(int s,int parent)
	{
		visited[s]=true;
		for(auto u:s)
		{
			if(visited[u]==0 &&	dfsRec(u,s)==true)
				return true;
			
			else if(u!=parent)
				return true;
		}
		return false;

	}


	bool dfs(int v)
	{
			
		for(int i:l)
			if(visited[i]==false &&	dfsRec(i,-1)==true)
					return true;
		return false;		
		
	}	
	
};

int main()
{
	Graph g;
	g.N=6;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(4,5);
	
	g.dfs(0);
	
	/*if(dfs(0))	
		cout<<"cycle is detected"<<endl;
	else
		cout<<"cycle is not detected"<<endl;*/
	
	return 0;	
}