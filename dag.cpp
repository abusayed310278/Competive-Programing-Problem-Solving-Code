#include<bits/stdc++.h>

using namespace std;
class Graph
{
	list<int>*l;
	bool *visited;
	int v;
public:
	Graph(int v){
		this->v=v;
		visited=new bool[v]{false};
	}
    void addEdge(int x,int y)
	{
		l[x].push_back(y);
		//l[y].push_back(x);
		
	}
	
	bool dfsRec(int src,int parent)
	{
		visited[src]=true;
		for(auto nbr:l[src])
		{
			if(!visited[nbr] && dfsRec(nbr,src))
				return true;
			
			else if(src!=parent)
				return true;
		}
		return false;

	}


	bool solve()
	{
			
		for(int i=0;i<v;i++)
			if(!visited[i] && dfsRec(i,-1))	return true;
		return false;		
		
	}	
	
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n;cin>>n;

	Graph g(n);

	while(n--){
		int x,y;cin>>x>>y;
		g.addEdge(x,y);
	}

	//g.solve();
	
	if(g.solve())	
		cout<<"cycle is detected"<<endl;
	else
		cout<<"cycle is not detected"<<endl;
	
	return 0;	
}

/*
6
0 1
1 2
1 3
2 3
2 4
4 5


*/