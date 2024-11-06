#include<bits/stdc++.h>
using namespace std; 

//not complete yet

class Graph{
	int n;
	list<int>*l;
public:
	Graph(int n){
		this->n=n;
		l=new list<int>[n];
	}
	void addEdge(int i,int j,bool undir=true){
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
	void dfsHelper(int node,bool *d,int parent=-1){
		d[node]=true;
		

		for(auto nbr:l[node]){
			if(nbr!=parent){
				dfsHelper(nbr,d,node);
			}
		}
		return;
	}

	void dfs(int src){

		bool *d=new bool[n]{0};
		dfsHelper(src,d);
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
	g.dfs(1);
	return 0;
}

/*

7
1 2
1 4
2 3
4 3
3 5
3 6
5 6

*/