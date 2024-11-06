#include<bits/stdc++.h>
using namespace std; 

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
	void dfs(int cur,int parent){
		
		cout<<cur<<" ";
		for(auto x:l[cur]){
			if(x!=parent)
				dfs(x,cur);
		}
	}

	
	
};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;cin>>n;
	Graph g(n);

	while(n--){
		int x,y;cin>>x>>y;
		g.addEdge(x,y);
	}

	//g.printAdjList();
	g.dfs(0,-1);
	return 0;
}

/*

3
0 1
1 2
2 0

*/