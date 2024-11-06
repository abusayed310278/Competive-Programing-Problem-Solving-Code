#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int>*l;
public:
	Graph(int v){
		V=v;
		l=new list<int>[V];
	}
	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}

	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			for(auto node:l[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
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

	g.printAdjList();
	return 0;
}

/*

4
0 1
0 2
1 3
2 3

*/