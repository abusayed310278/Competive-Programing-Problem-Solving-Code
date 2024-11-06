#include<bits/stdc++.h>
using namespace std; 

class Graph{
	int v,e;
	list<pair<int,int>>*l;
	bool *visited;
	int *dist;
	
public:
	Graph(int v,int e){
		this->v=v;
		this->e=e;
		l=new list<int>[n];
		visited=new bool[n]{0};
		dist=new int[n]{0};
		
	}
	void addEdge(int u,int v,int w){
		l[u].push_back(make_pair(y,w));
		
	}

	void print()
	{	
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			//auto nbrs=l[i];
			for(auto nbr:l[i]){
				cout<<"("<<nbr.first<<" "<<nbr.second<<")"<<",";
			}
			cout<<endl;
		}
	}
	
	

	
};

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;cin>>n;
	Graph g(n);

	while(n--){
		int x,y;cin>>x>>y;
		g.addEdge(x,y);
	}

	//g.printAdjList();
	g.bfs(1);
	return 0;
}

/*

7
0 1
1 2
3 5
5 6
4 5
0 4
3 4

*/