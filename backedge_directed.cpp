#include<bits/stdc++.h>
using namespace std; 

bool cycle=false;
//backedge find code by alom paul for directed graph and undirected graph
class Graph{
	int n;
	list<int>*l;
public:
	Graph(int n){
		this->n=n;
		l=new list<int>[n];
	}
	void addEdge(int i,int j,bool undir=false){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}

	void printAdjList(){
		for(int i=0;i<n;i++){
			cout<<i<<"->";
			for(auto node:l[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}

	void dfsHelper(int cur,int parent,vector<int>& visited){
		//visited and in call stack
		//cout<<cur<<endl;
		visited[cur]=1;

		for(auto x:l[cur]){
			//visited ==0 
			if(!visited[x])dfsHelper(x,cur,visited);
			else if(x!=parent && visited[x]==1)
				//cout<<cur<<" "<<x<<endl; //backedge code
			cycle=true;
		}
		//visited and not in call stack
		visited[cur]=2;
		return;
	}
	
	void dfs(){
		vector<int>visited(n,0);
		for(int i=0;i<n;i++)
			if(!visited[i])dfsHelper(i,-1,visited);
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

	//g.printAdjList();
	g.dfs();

	if(cycle==true)
		cout<<"yes cycle";
	else
		cout<<"no cycle";

	return 0;
}

/*

3
0 1
1 2
2 0

*/