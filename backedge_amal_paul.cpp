#include<bits/stdc++.h>
using namespace std; 

//backedge find code by alom paul for undirected graph
class Graph{
	int n;
	list<int>*l;
	bool cycle;
public:
	Graph(int n){
		this->n=n;
		l=new list<int>[n];
		cycle=false;
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

	void dfsHelper(int cur,int parent,vector<bool>& visited){
		cout<<cur<<endl;
		visited[cur]=true;

		for(auto x:l[cur]){
			if(!visited[x])dfsHelper(x,cur,visited);
			else if(x!=parent)cout<<cur<<" "<<x<<endl; //backedge code
			//cycle=true;
		}
	}
	
	void dfs(){
		vector<bool>visited(n,false);
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
	return 0;
}

/*

3
0 1
1 2
2 0

*/